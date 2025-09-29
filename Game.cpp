#include "Game.h"
#include <iostream>
#include <string>


void Game::cmdUse(const std::string& target) {
// simple use rules:
if (target == "mirror_frag" || target == "mirror") {
if (_player.hasItem("mirror_frag")) {
std::cout << "You use the mirror fragment to reflect sunlight and signal.\n";
std::cout << "A passing ship notices the signal! Rescue is on its way.\n";
_running = false; // win condition
return;
}
std::cout << "You don't have that.\n";
return;
}
if (target == "vine" || target == "plank") {
if (_player.hasItem("vine") && _player.hasItem("wood_plank")) {
std::cout << "You lash a plank and vine together to craft a makeshift raft.\n";
std::cout << "You push it into the surf and paddle out to sea...\n";
_running = false; // win condition
return;
}
std::cout << "You need both a vine and a wood plank to build a raft.\n";
return;
}
if (target == "can") {
if (_player.hasItem("can")) {
std::cout << "You shake the can to scare birds or use it to collect small things. Not very useful now.\n";
return;
}
std::cout << "You don't have that.\n";
return;
}
std::cout << "You can't use that now.\n";
}


void Game::showHelp() const {
std::cout << "Commands:\n";
std::cout << " look / l - look around\n";
std::cout << " go <dir> / g <dir> - move (e.g. go north)\n";
std::cout << " take <item> - pick up an item\n";
std::cout << " use <item> - use an item (mirror, vine, plank)\n";
std::cout << " inv / inventory - show inventory\n";
std::cout << " quit - quit game\n";
}


bool Game::checkWin() const {
// winning can be triggered by state in use commands; keep this for future checks
return false;
}