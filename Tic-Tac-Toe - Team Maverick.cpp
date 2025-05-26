#include <bits/stdc++.h>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

const int BOARD_SIZE = 3;
const int MOVE_TIME_LIMIT = 10;
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

int scores[3] = {0};
bool soundEnabled = true;

void initializeBoard(vector<vector<char>>& board);
void displayBoard(const vector<vector<char>>& board);
void displayScores();
bool makeMove(vector<vector<char>>& board, int row, int col, char player);
bool isMoveValid(const vector<vector<char>>& board, int row, int col);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);
void computerMove(vector<vector<char>>& board, char computer);
void playSound(int type);
void clearScreen();
bool getPlayerInputWithTimer(const string& prompt, int& input);
void playerVsPlayer();
void playerVsComputer();
void gameLoop(bool vsComputer);
void mainMenu();

int main()
{
    srand(time(0));
    mainMenu();
    return 0;
}

void mainMenu()
{
    while (true)
    {
        clearScreen();
        cout << "=== TIC TAC TOE GAME ===" << endl;
        cout << "1. Player vs Player" << endl;
        cout << "2. Player vs Computer" << endl;
        cout << "3. Toggle Sound (" << (soundEnabled ? "ON" : "OFF") << ")" << endl;
        cout << "4. Reset Scores" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            continue;
        }

        switch (choice)
        {
        case 1:
            playerVsPlayer();
            break;
        case 2:
            playerVsComputer();
            break;
        case 3:
            soundEnabled = !soundEnabled;
            cout << "Sound is now " << (soundEnabled ? "ON" : "OFF") << endl;
            this_thread::sleep_for(chrono::seconds(1));
            break;
        case 4:
            scores[0] = scores[1] = scores[2] = 0;
            cout << "Scores have been reset." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            break;
        case 5:
            cout << "Thanks for playing!" << endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
}

void initializeBoard(vector<vector<char>>& board)
{
    board.clear();
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        vector<char> row;
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            row.push_back(EMPTY);
        }
        board.push_back(row);
    }
}

void displayBoard(const vector<vector<char>>& board)
{
    clearScreen();
    cout << "=== TIC TAC TOE ===" << endl;
    displayScores();
    cout << endl;

    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        cout << " ";
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            cout << board[i][j];
            if (j < BOARD_SIZE - 1) cout << " | ";
        }
        cout << endl;

        if (i < BOARD_SIZE - 1)
        {
            cout << "-----------" << endl;
        }
    }
    cout << endl;
}

void displayScores()
{
    cout << "Scores - X: " << scores[0] << " | O: " << scores[1] << " | Draws: " << scores[2] << endl;
}

bool makeMove(vector<vector<char>>& board, int row, int col, char player)
{
    if (isMoveValid(board, row, col))
    {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool isMoveValid(const vector<vector<char>>& board, int row, int col)
{
    return row >= 0 && row < BOARD_SIZE &&
           col >= 0 && col < BOARD_SIZE &&
           board[row][col] == EMPTY;
}

bool checkWin(const vector<vector<char>>& board, char player)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }

    for (int j = 0; j < BOARD_SIZE; ++j)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

bool checkDraw(const vector<vector<char>>& board)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (board[i][j] == EMPTY)
            {
                return false;
            }
        }
    }
    return true;
}

void computerMove(vector<vector<char>>& board, char computer)
{
    char human = (computer == PLAYER_X) ? PLAYER_O : PLAYER_X;

    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = computer;
                if (checkWin(board, computer))
                {
                    playSound(1);
                    return;
                }
                board[i][j] = EMPTY;
            }
        }
    }

    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = human;
                if (checkWin(board, human))
                {
                    board[i][j] = computer;
                    playSound(1);
                    return;
                }
                board[i][j] = EMPTY;
            }
        }
    }

    if (board[1][1] == EMPTY)
    {
        board[1][1] = computer;
        playSound(1);
        return;
    }

    vector<pair<int, int>> corners = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    for (const auto& corner : corners)
    {
        if (board[corner.first][corner.second] == EMPTY)
        {
            board[corner.first][corner.second] = computer;
            playSound(1);
            return;
        }
    }

    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = computer;
                playSound(1);
                return;
            }
        }
    }
}

void playSound(int type)
{
    if (!soundEnabled) return;

#ifdef _WIN32
    switch (type)
    {
    case 0:
        Beep(300, 200);
        break;
    case 1:
        Beep(500, 100);
        break;
    case 2:
        Beep(800, 300);
        Beep(1000, 300);
        break;
    case 3:
        Beep(400, 200);
        Beep(300, 300);
        break;
    }
#else
    const char* sounds[] = {"[ERROR SOUND]", "[MOVE SOUND]", "[WIN SOUND]", "[DRAW SOUND]"};
    cout << sounds[type] << flush;
#endif
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

bool getPlayerInputWithTimer(const string& prompt, int& input)
{
    input = -1;
    bool inputReceived = false;

    cout << prompt << " (You have " << MOVE_TIME_LIMIT << " seconds): ";
    cout.flush();

    auto start = chrono::steady_clock::now();
    thread inputThread([&]()
    {
        if (!(cin >> input))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        inputReceived = true;
    });

    inputThread.detach();

    while (true)
    {
        auto now = chrono::steady_clock::now();
        auto elapsed = chrono::duration_cast<chrono::seconds>(now - start).count();

        if (inputReceived)
        {
            return true;
        }

        if (elapsed >= MOVE_TIME_LIMIT)
        {
            cout << "\nTime's up! ";
            playSound(0);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }

        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void playerVsPlayer()
{
    gameLoop(false);
}

void playerVsComputer()
{
    gameLoop(true);
}

void gameLoop(bool vsComputer)
{
    vector<vector<char>> board;
    initializeBoard(board);
    char currentPlayer = PLAYER_X;
    bool gameRunning = true;

    while (gameRunning)
    {
        displayBoard(board);

        if (currentPlayer == PLAYER_O && vsComputer)
        {
            cout << "Computer's turn (O)..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            computerMove(board, PLAYER_O);
        }
        else
        {
            cout << "Player " << currentPlayer << "'s turn" << endl;

            int row, col;
            bool gotRow = getPlayerInputWithTimer("Enter row (1-3)", row);
            if (!gotRow || row < 1 || row > 3)
            {
                cout << "Invalid input or time out. Try again." << endl;
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }

            bool gotCol = getPlayerInputWithTimer("Enter column (1-3)", col);
            if (!gotCol || col < 1 || col > 3)
            {
                cout << "Invalid input or time out. Try again." << endl;
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }
            row--;
            col--;

            if (!makeMove(board, row, col, currentPlayer))
            {
                cout << "Invalid move! That spot is already taken or out of range." << endl;
                playSound(0);
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }

            playSound(1);
        }

        if (checkWin(board, currentPlayer))
        {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            playSound(2);

            if (currentPlayer == PLAYER_X) scores[0]++;
            else scores[1]++;

            gameRunning = false;
        }
        else if (checkDraw(board))
        {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            playSound(3);
            scores[2]++;
            gameRunning = false;
        }
        else
        {
            currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }

    cout << "\n1. Play again" << endl;
    cout << "2. Main menu" << endl;
    cout << "Choose an option: ";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        gameLoop(vsComputer);
    }
    else
    {
        mainMenu();
    }
}
