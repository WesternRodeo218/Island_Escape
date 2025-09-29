// FILE: Game.h
#ifndef GAME_H
#define GAME_H


#include "Player.h"
#include "Island.h"
#include <string>


class Game {
public:
Game();
void run();


private:
void printWelcome();
void describeLocation() const;
void processCommand(const std::string& cmd);
void cmdLook();
void cmdGo(const std::string& dir);
void cmdTake(const std::string& target);
void cmdUse(const std::string& target);
void showHelp() const;
bool checkWin() const;


Player _player;
Island _island;
bool _running{true};
};


#endif // GAME_H