#ifndef __LOCATION_HPP__
#define __LOCATION_HPP__
#include <string>
class Location
{
public:
    Location(std::string _name, double _latitude, double _longitude);
    std::string get_name();
private:
    std::string name;
    double latitude;
    double longitude;
};
#endif /* __LOCATION_HPP__ */