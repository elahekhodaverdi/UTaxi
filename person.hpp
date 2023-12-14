#ifndef __PERSON_HPP__
#define __PERSON_HPP__
#include <string>
#include "define.hpp"
#include "trip.hpp"
#include <exception>
class Data;

class Person
{
public:
    Person(std::string _name);
    std::string get_name();
    virtual void add_trip_for_post(Trip *_trip) = 0;
    virtual void accept_trip(Trip *_trip) = 0;
    void change_info_after_accept();
    void change_info_after_finish();
    virtual void finish_trip(Trip *_trip) = 0;
    virtual void show_trip_info(Trip *_trip) = 0;
    virtual void delete_trip(Trip *_trip) = 0;
protected:
    std::string name;
    State state;
    Trip *trip;
};

#endif