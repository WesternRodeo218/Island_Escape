 
#include "Island.h"
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

// Assuming Item and Location are defined in Island.h or elsewhere

void Island::setup() {
    // Beach
    Location beach;
    beach.id = "beach";
    beach.name = "Sandy Beach";
    beach.description = "You lie on a sun-bleached beach. There is wreckage scattered around.";
    beach.exits = {{"north", "jungle"}};
    beach.items.push_back(std::make_shared<Item>("wood_plank", "Wood Plank", "A sturdy plank from the wreck."));
    _locations[beach.id] = std::move(beach);
    _startId = "beach";

    // Jungle
    Location jungle;
    jungle.id = "jungle";
    jungle.name = "Dense Jungle";
    jungle.description = "Thick foliage blocks the sunlight. You hear distant bird calls.";
    jungle.exits = {{"south", "beach"}, {"east", "clearing"}};
    jungle.items.push_back(std::make_shared<Item>("vine", "Vine", "A long resilient vine, useful for tying things."));
    _locations[jungle.id] = std::move(jungle);

    // Clearing
    Location clearing;
    clearing.id = "clearing";
    clearing.name = "Forest Clearing";
    clearing.description = "A calm clearing with a small pond. Something metallic glints under a bush.";
    clearing.exits = {{"west", "jungle"}, {"north", "cliff"}};
    clearing.items.push_back(std::make_shared<Item>("can", "Empty Can", "An old metal can (could scare birds).", true));
    clearing.items.push_back(std::make_shared<Item>("mirror_frag", "Mirror Fragment", "A small reflective shard - might be used to signal."));
    _locations[clearing.id] = std::move(clearing);

    // Cliff
    Location cliff;
    cliff.id = "cliff";
    cliff.name = "Coastal Cliff";
    cliff.description = "The cliff overlooks the sea. In the distance you can see a shipping lane.";
    cliff.exits = {{"south", "clearing"}};
    _locations[cliff.id] = std::move(cliff);
}

const Location* Island::getLocation(const std::string& id) const {
    auto it = _locations.find(id);
    if (it == _locations.end()) return nullptr;
    return &it->second;
}
Location* Island::getLocationMutable(const std::string& id) {
    auto it = _locations.find(id);
    if (it == _locations.end()) return nullptr;
    return &it->second;
}
const Location* Island::startLocation() const {
    return getLocation(_startId);
}