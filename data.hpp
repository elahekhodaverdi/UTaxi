#ifndef __DATA_HPP__
#define __DATA_HPP__
#include <vector>
#include <iostream>
#include "trip.hpp"
#include "passenger.hpp"
#include "driver.hpp"
#include "person.hpp"
#include "location.hpp"
#include <exception>
class Data
{
public:
    void add_location(Location *);
    void add_user(Person *);
    bool user_already_exists(Person *);
    void post_trip(std::string, std::string, std::string);
    Location *find_location(std::string);
    Person *find_user(std::string);
    void accept(std::string, int);
    Trip *find_trip(int);
    void finish_a_trip(std::string, int);
    void show_trip_info(std::string, int id);
    void show_trips(std::string);
    void delete_trip(std::string,int );
    bool is_available_any_trip();

private:
    std::vector<Trip *> trips;
    std::vector<Location *> locations;
    std::vector<Person *> users;
};
#endif