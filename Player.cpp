// FILE: Player.cpp
#include "Player.h"
#include "Item.h" // Item.h must contain the full definition of Item, not just a forward declaration
#include <iostream>


Player::Player(std::string name) : _name(std::move(name)) {}


void Player::setLocation(const std::string& loc) { _location = loc; }
const std::string& Player::location() const { return _location; }


void Player::addItem(std::shared_ptr<Item> item) { _inventory.push_back(std::move(item)); }
bool Player::hasItem(const std::string& id) const {
for (auto &i : _inventory) if (i->id() == id) return true;
return false;
}


std::shared_ptr<Item> Player::takeItem(const std::string& id) {
for (size_t idx=0; idx<_inventory.size(); ++idx) {
if (_inventory[idx]->id() == id) {
auto it = _inventory.begin() + idx;
auto item = *it;
_inventory.erase(it);
return item;
}
}
return nullptr;
}


void Player::listInventory() const {
if (_inventory.empty()) { std::cout << "(empty)\n"; return; }
for (auto &i : _inventory) std::cout << " - " << i->name() << "\n";
}


int Player::health() const { return _health; }
void Player::changeHealth(int delta) { _health += delta; if (_health > 100) _health = 100; }