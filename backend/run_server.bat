@echo off
cd /d %~dp0
echo Running Flask Server...
set FLASK_APP=server.py
set FLASK_ENV=development
python server.py
pause
