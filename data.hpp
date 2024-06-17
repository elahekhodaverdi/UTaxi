#ifndef __DATA_HPP__
#define __DATA_HPP__
#include <vector>
#include <iostream>
#include "trip.hpp"
#include "passenger.hpp"
#include "driver.hpp"
#include "person.hpp"
#include "location.hpp"
#include "exceptions.hpp"
#include <algorithm>
class Data
{
public:
    void add_location(Location *);
    void add_user(Person *);
    bool user_already_exists(Person *);
    int post_trip(std::string, std::string, std::string, std::string);
    Location *find_location(std::string);
    Person *find_user(std::string);
    void accept(std::string, int);
    Trip *find_trip(int);
    void finish_a_trip(std::string, int);
    Trip* show_trip_info(std::string, int id);
    std::vector<Trip*> show_trips(std::string, bool);
    void print_trips(bool);
    void delete_trip(std::string, int);
    bool is_available_any_trip();
    double get_cost(std::string, std::string, std::string, std::string);

private:
    std::vector<Trip *> trips;
    std::vector<Location *> locations;
    std::vector<Person *> users;
};
bool compare_trips_cost(Trip *, Trip *);
#endif