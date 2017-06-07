@echo off

.\cbmc64.exe sudoku.cpp --error-label match --trace | .\grep .stream | .\tail --lines=1 | .\grep -oP "={ \d[^}]*}" >solution.inc

del sudoku_chk.exe >nul 2>nul

call .\cl.bat sudoku_chk.cpp 

sudoku_chk.exe
