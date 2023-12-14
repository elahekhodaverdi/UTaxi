#ifndef __TRIP_HPP__
#define __TRIP_HPP__
#include "define.hpp"
#include "location.hpp"
#include <string>
#include <map>

class Person;
class Trip
{
public:
    Trip(Person *, Location *, Location *, int _id);
    bool has_same_id_with(int);
    void change_info_after_accept(Person *_driver);
    void change_info_after_finish();
    void show_trip_info();
    bool operator==(const Trip &);
    bool is_cancelled();
    void delete_trip();

private:
    Location *origin;
    Location *destination;
    State state;
    int id;
    Person *passenger;
    Person *driver;
};
#endif