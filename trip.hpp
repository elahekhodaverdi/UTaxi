#ifndef __TRIP_HPP__
#define __TRIP_HPP__
#include "define.hpp"
#include "location.hpp"
#include "exceptions.hpp"
#include <string>
#include <map>
#include <iomanip>
#include <iostream>
#include <sstream>
class Person;
class Trip;
bool operator==(Trip &trip1, Trip &trip2);
class Trip
{
public:
    Trip(Person *, Location *, Location *, int, bool);
    bool has_same_id_with(int);
    void change_info_after_accept(Person *_driver);
    void change_info_after_finish();
    void show_trip_info();
    bool operator==(const Trip);
    bool is_cancelled();
    void delete_trip();
    bool is_expensive_than(Trip *);
    bool operator==(Trip *trip);
    void complete_body_response(std::ostringstream &body, std::string);

private:
    Location *origin;
    Location *destination;
    State state;
    int id;
    double cost;
    bool hurry;
    Person *passenger;
    Person *driver;
};
#endif