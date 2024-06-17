#ifndef __PASSENGER_HPP__
#define __PASSENGER_HPP__
#include "person.hpp"
#include <iostream>

class Passenger : public Person
{
public:
    Passenger(std::string _name);
    void add_trip_for_post(Trip *_trip);
    void accept_trip(Trip *_trip);
    void change_info_after_accept();
    void finish_trip(Trip *_trip);
    void change_info_after_finish();
    Trip* show_trip_info(Trip *_trip);
    void show_trips(Data &data);
    void delete_trip(Trip *_trip);
    double get_cost_trip(Location *, Location *, std::string);
private:
};
#endif
