#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__
#include "person.hpp"
#include <iostream>
#include "define.hpp"
class Data;
class Driver : public Person
{
public:
    Driver(std::string _name);
    void add_trip_for_post(Trip *_trip);
    void accept_trip(Trip *_trip);
    void change_info_after_accept(Trip *_trip);
    void finish_trip(Trip *_trip);
    void change_info_after_make_trip();
    Trip* show_trip_info(Trip *_trip);
    void delete_trip(Trip *_trip);
    double get_cost_trip(Location *, Location *, std::string);

private:
};
#endif
