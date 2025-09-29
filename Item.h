#pragma once
#include <string>
#include <vector>
#include <memory>

// Forward declaration of Item class
class Item;

class Location {
public:
    std::string id;
    std::string name;
    std::string description;
    std::vector<std::shared_ptr<Item>> items;

    Location(const std::string& id, const std::string& name, const std::string& description);
};

class Island {
public:
    std::vector<Location> locations;

    Island();
};

class Item {
public:
    Item(std::string id, std::string name);
    const std::string& id() const;
    const std::string& name() const;
private:
    std::string _id;
    std::string _name;
};
