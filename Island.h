// FILE: Island.h
#ifndef ISLAND_H
#define ISLAND_H


#include <string>
#include <unordered_map>
#include <vector>
#include <memory>


class Item;


    struct Location {
    std::string id;
    std::string name;
    std::string description;
    std::unordered_map<std::string,std::string> exits; // dir -> location id
    std::vector<std::shared_ptr<Item>> items;
    Location() = default;
    };


class Island {
public:
Island();
const Location* getLocation(const std::string& id) const;
Location* getLocationMutable(const std::string& id);
const Location* startLocation() const;
void setup();


private:
std::unordered_map<std::string, Location> _locations;
std::string _startId;
};


#endif // ISLAND_H