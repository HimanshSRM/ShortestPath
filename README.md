# Shortest Path Project - Setup Guide

## Requirements
- Python 3.x
- Flask (`pip install flask`)
- g++ Compiler (for compiling C++ code)

## Setup Steps

1. Compile C++ backend
   Open Command Prompt in 'backend/' folder:
   > g++ singleSourceShortestPath.cpp -o singleSourceShortestPath.exe

2. Install Flask if not already:
   > pip install flask

3. Start Backend Server
   Double-click 'run_server.bat' inside backend/ folder.

4. Open Frontend
   Open 'frontend/index.html' directly in your browser.

## Usage
- Enter graph input in textarea.
- Click "Calculate Shortest Path".
- Result will be shown below.

