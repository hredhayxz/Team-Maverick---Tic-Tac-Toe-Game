# Team-Maverick---Tic-Tac-Toe-Game

Enhanced Console-Based Tic Tac Toe Game

Project Overview
This project reimagines the classic Tic Tac Toe game, built using C++ to deliver an engaging and interactive console-based experience. The game retains the traditional 3x3 grid while introducing modern features such as single-player mode against a computer opponent, real-time score tracking, move timers, and immersive sound effects (where supported). These enhancements create a dynamic and fast-paced gameplay environment suitable for players of all ages.
Players can compete against each other or challenge a computer opponent. A scoreboard tracks wins, losses, and draws across multiple rounds, while time-limited turns add urgency and excitement. The project combines classic game mechanics with modern features to provide a stimulating and enjoyable experience.
Features

Console-Based Gameplay: A fully functional Tic Tac Toe game running in a terminal/command-line interface.
Single and Multiplayer Modes: Play against another player or a computer opponent with basic AI logic.
Real-Time Score Tracking: Records wins, losses, and draws across multiple rounds.
Move Timer: Introduces time-limited turns to add urgency and excitement.
Sound Effects: Enhances immersion with auditory feedback (where supported).
Error Handling: Robust validation of user inputs and graceful handling of edge cases.
Intuitive UI: A clear text-based interface to display the game board, prompts, and status updates.

Technical Details

Programming Language: C++
Compiler: GCC
IDE: Visual Studio Code or Code::Blocks
Version Control: Git
Dependencies: Standard C++ libraries; no external dependencies required.

Project Structure

Game Board Implementation
Uses a 2D array to represent the 3x3 Tic Tac Toe board.
Includes a function to visually display the board in the console.


Player and Computer Interaction
Handles and validates player inputs for move selection.
Alternates turns between Player 1, Player 2, or the computer opponent.


Win and Draw Logic
Detects winning patterns (horizontal, vertical, diagonal).
Identifies draw conditions when the board is full.


User Experience
Displays clear prompts, real-time updates, and game outcomes.
Implements a countdown timer for each move to increase engagement.
Includes sound feedback for enhanced immersion (where supported).


Error Handling
Validates all user inputs to prevent invalid moves.
Manages edge cases with appropriate user messages.



Setup Instructions

Clone the Repository:git clone https://github.com/hredhayxz/Team-Maverick---Tic-Tac-Toe-Game.git
cd Team-Maverick---Tic-Tac-Toe-Game


Compile the Code:Ensure GCC is installed, then run:g++ -o tictactoe main.cpp


Run the Game:./tictactoe


Gameplay:
Follow the on-screen prompts to enter moves (e.g., row and column numbers).
In single-player mode, compete against the computer.
Use the menu to restart or exit after each game.



Team Information
Team Name: MaverickInstitution: Northern University Bangladesh, Department of Computer Science and Engineering (ECSE)Course: Software Development I (C++ Programming), Course Code: CSE 1290, Semester: 2nd, Section: D
Team Members

Zahid Hasan (42240301951) - Project Lead
Md Alhaz Mondal (42240301932) - Developer
Hadiul Islam Hadi (42240302006) - Developer
Md Altaf Mahmud (42240301998) - Developer
Syfur Rahman Ruman (42240301969) - Tester
Gobindo Saha (42240302006) - Documentation Writer

Learning Outcomes
Through this project, the team developed the following skills:

Proficiency in C++ programming, including control structures, functions, and arrays.
Modular code design using object-oriented principles and functions.
Implementation of basic computer AI logic for the opponent.
Debugging and troubleshooting techniques for robust code.
Collaborative version control using Git.
Designing clear and user-friendly console-based interfaces.

Submission Components

Source Code: Well-documented C++ source files.
Executable File: A compiled binary to run the game.
Documentation:
User Guide: Instructions for gameplay and setup.
Code Comments: In-line comments explaining logic and design rationale.
Technical Report: Overview of the development process and architecture.



Conclusion
The Enhanced Console-Based Tic Tac Toe Game is a practical demonstration of C++ programming skills, blending fundamental coding concepts with interactive game design. This project reinforces key programming techniques such as control structures, functions, arrays, and error handling while introducing students to game logic and turn-based interactions. It serves as an engaging entry point into software development, delivering both educational value and an enjoyable user experience.
