#include "driver.hpp"
#include "data.hpp"
Driver::Driver(std::string _name) : Person(_name) {}
void Driver::add_trip_for_post(Trip *_trip)
{
    delete _trip;
    throw std::logic_error(PERMISSION_DENIED_ERROR);
}
void Driver::accept_trip(Trip *_trip)
{
    if (state != FINISHED)
        throw std::logic_error(BAD_REQUEST_ERROR);

    trip = _trip;
    trip->change_info_after_accept(this);
    state = TRAVELING;
    std::cout << SUCCESS_MESSAGE << std::endl;
}

void Driver::finish_trip(Trip *_trip)
{
    if (*_trip == *trip)
    {
        change_info_after_finish();
        _trip->change_info_after_finish();
        std::cout << SUCCESS_MESSAGE << std::endl;
    }
    else
        throw std::logic_error(PERMISSION_DENIED_ERROR);
}

void Driver::show_trip_info(Trip *_trip)
{

    _trip->show_trip_info();
}

void Driver::delete_trip(Trip *_trip)
{
    throw std::logic_error(PERMISSION_DENIED_ERROR);
}
