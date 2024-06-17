#include "passenger.hpp"
using namespace std;
Passenger::Passenger(string _name)
    : Person(_name)
{
}

void Passenger::add_trip_for_post(Trip *_trip)
{
    if (state == FINISHED)
    {
        trip = _trip;
        state = WAITING;
    }
    else
    {
        throw BadRequest();
    }
}

void Passenger::accept_trip(Trip *_trip)
{
    throw PermissionDenied();
}

void Passenger::change_info_after_accept()
{
    state = TRAVELING;
}

void Passenger::finish_trip(Trip *_trip)
{
    throw PermissionDenied();
}

Trip* Passenger::show_trip_info(Trip *_trip)
{
    throw PermissionDenied();
}

void Passenger::show_trips(Data &data)
{
    throw PermissionDenied();
}

void Passenger::delete_trip(Trip *_trip)
{
    if (*_trip == trip)
    {
        trip->delete_trip();
        state = FINISHED;
        trip = NULL;
    }
    else
        throw PermissionDenied();
}

double Passenger::get_cost_trip(Location *origin, Location *destination, std::string hurry)
{
    double cost = origin->cal_trip_cost(destination);
    if (hurry == YES)
        return (1.2) * cost;
    else
        return cost;
}
