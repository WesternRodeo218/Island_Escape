#include "Location.h"


Location::Location(const std::string& n, const std::string& d) : name(n), description(d) {}


std::string Location::getName() const {
return name;
}


std::string Location::getDescription() const {
return description;
}