@echo off
rem Usage: run.bat <source.cpp> <problem dir>
for %%I in ("%~dp0..") do set "ROOT=%%~fI"
set "OUT=%ROOT%\.build"
if not exist "%OUT%" mkdir "%OUT%"
g++ -std=c++17 -O2 -Wall -Wextra -Wshadow "%~1" -o "%OUT%\run.exe" || exit /b 1
"%OUT%\run.exe" < "%~2\input.txt" > "%~2\output.txt"
exit /b %errorlevel%
