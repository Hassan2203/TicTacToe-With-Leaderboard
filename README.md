# TicTacToe-With-Leaderboard

🎮 Noughts and Crosses (Tic Tac Toe) – C++ Project
👨‍💻 Developed By

Hassan Ali Ahmad
(With collaboration of Kinza Wajid)

📌 Project Description

This is a console-based implementation of the classic Tic Tac Toe (Noughts and Crosses) game developed in C++.

The project includes:

Human vs Human mode

Human vs Computer mode

Save and Load game feature

Leaderboard system

File handling

ASCII-based interactive UI

This project demonstrates concepts of:

Structures

File Handling

Vectors

Functions

Loops

Conditional Statements

Random number generation

🚀 Features
🎯 Game Modes

✅ Human vs Human

✅ Human vs Computer (Random AI)

💾 Save & Load System

Saves ongoing game to file

Loads previously saved game

🏆 Leaderboard System

Tracks number of wins

Automatically sorts players by highest wins

Separate leaderboard for:

Human vs Human

Human vs PC

🎨 Console UI

ASCII characters used for board design

Clear screen effect

Interactive menu system

🛠 Technologies Used

C++

File Handling (fstream)

STL Vector

String Stream

iomanip

Random number generator

📂 File Structure
File	Purpose
main.cpp	Main source code
2human.txt	Save file for Human vs Human
humanvspc.txt	Save file for Human vs PC
2human_leaderboard.txt	Leaderboard (Human vs Human)
human_vs_pc_leaderboard.txt	Leaderboard (Human vs PC)
🧠 How The Game Works

Player selects game mode.

Toss decides first turn.

Players select symbols (X or O).

Game checks:

Row match

Column match

Diagonal match

Winner is recorded in leaderboard.

If board is full → Game Draw.
