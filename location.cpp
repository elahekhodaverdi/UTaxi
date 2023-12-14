#include "location.hpp"
Location::Location(std::string _name, double _latitude, double _longitude)
{
    name = _name;
    latitude = _latitude;
    longitude = _longitude;
}

std::string Location::get_name()
{
    return name;
}