#ifndef __LOCATION_HPP__
#define __LOCATION_HPP__
#include <string>
#include <math.h>
class Location
{
public:
    Location(std::string _name, double _latitude, double _longitude, double _traffic);
    std::string get_name();
    double cal_trip_cost(Location*);
private:
    std::string name;
    double latitude;
    double longitude;
    double traffic;
};
#endif /* __LOCATION_HPP__ */