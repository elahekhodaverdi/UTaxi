#include "location.hpp"
Location::Location(std::string _name, double _latitude, double _longitude, double _traffic)
{
    name = _name;
    latitude = _latitude;
    longitude = _longitude;
    traffic = _traffic;
}

std::string Location::get_name()
{
    return name;
}

double Location::cal_trip_cost(Location *second_location)
{
    double dist = 110.5 * (sqrt(pow(latitude - second_location->latitude, 2) + pow(longitude - second_location->longitude, 2)));
    double price = dist * (traffic + second_location->traffic) * 10000;
    return price;
}