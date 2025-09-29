/*
Island Escape - Text-based C++ Game (multi-file, OOP)


Compile:
g++ -std=c++17 -O2 *.cpp -o island_escape


Run:
./island_escape


Description:
You play as a man who crash-landed on an abandoned island. Explore locations, pick up items,
solve simple puzzles, and try to get rescued or build a raft to escape.


Files included below (each starts with a comment header):
- main.cpp
- Game.h / Game.cpp
- Player.h / Player.cpp
- Island.h / Island.cpp
- Item.h / Item.cpp
- Makefile




Design notes:
- Simple map of named locations connected by directions.
- Inventory system with Items that can be examined/used.
- Save/load hooks can easily be added later.
*/