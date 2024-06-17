#include "driver.hpp"
#include "data.hpp"
Driver::Driver(std::string _name) : Person(_name) {}
void Driver::add_trip_for_post(Trip *_trip)
{
    delete _trip;
    throw PermissionDenied();
}
void Driver::accept_trip(Trip *_trip)
{
    if (state != FINISHED)
        throw BadRequest();

    trip = _trip;
    trip->change_info_after_accept(this);
    state = TRAVELING;
}

void Driver::finish_trip(Trip *_trip)
{
    if (*_trip == trip)
    {
        change_info_after_finish();
        _trip->change_info_after_finish();
    }
    else
    {
        throw PermissionDenied();
    }
}

Trip *Driver::show_trip_info(Trip *_trip)
{

    return _trip;
}

void Driver::delete_trip(Trip *_trip)
{
    throw PermissionDenied();
}

double Driver::get_cost_trip(Location *, Location *, std::string)
{
    throw PermissionDenied();
}
