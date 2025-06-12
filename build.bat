@echo off
setlocal

REM --- Quell- und Ziel-Dateien ---
set SRC=Scrapen.cpp
set OUT=Scrapen.exe

REM --- Include- und Lib-Pfade ---
set INC=C:/msys64/ucrt64/include
set LIB=C:/msys64/ucrt64/lib

REM --- Compiler ---
set GPP=C:/msys64/ucrt64/bin/g++.exe

echo === Kompiliere mit g++ ===
"%GPP%" -std=c++17 -static -static-libgcc -static-libstdc++ -mwindows ^
  -I"%INC%" -L"%LIB%" ^
  "%SRC%" -o "%OUT%" ^
  -lnana -lole32 -luuid -loleaut32 -lcomctl32 -lshell32 -ljpeg -lpng -lz ^
  -lopengl32 -lglu32 -lglew32 -lcpr -lcurl

set ERR=%ERRORLEVEL%
echo ==========================
echo.

if %ERR%==0 (
    echo Build erfolgreich: %OUT%
) else (
    echo Build FEHLGESCHLAGEN!
)

pause