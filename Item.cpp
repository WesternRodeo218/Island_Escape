// FILE: Item.cpp
#include "Item.h"

// Implementation of Item methods
Item::Item(std::string id, std::string name)
    : _id(std::move(id)), _name(std::move(name)) {}

const std::string& Item::id() const { return _id; }
const std::string& Item::name() const { return _name; }