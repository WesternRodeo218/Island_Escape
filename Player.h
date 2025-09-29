#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Item.h"

class Player {
public:
    Player(std::string name = "Castaway");
    void setLocation(const std::string& loc);
    const std::string& location() const;
    void addItem(std::shared_ptr<Item> item);
    bool hasItem(const std::string& id) const;
    std::shared_ptr<Item> takeItem(const std::string& id);
    void listInventory() const;
    int health() const;
    void changeHealth(int delta);

private:
    std::string _name;
    std::string _location;
    std::vector<std::shared_ptr<Item>> _inventory;
    int _health = 100;
};

#endif // PLAYER_H