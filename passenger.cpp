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
        throw logic_error(BAD_REQUEST_ERROR);
}

void Passenger::accept_trip(Trip *_trip)
{
    throw logic_error(PERMISSION_DENIED_ERROR);
}

void Passenger::change_info_after_accept()
{
    state = TRAVELING;
}

void Passenger::finish_trip(Trip *_trip)
{
    throw logic_error(PERMISSION_DENIED_ERROR);
}

void Passenger::show_trip_info(Trip *_trip)
{
    throw logic_error(PERMISSION_DENIED_ERROR);
}

void Passenger::show_trips(Data &data)
{
    throw logic_error(PERMISSION_DENIED_ERROR);
}

void Passenger::delete_trip(Trip *_trip)
{
    if (*_trip == *trip)
    {
        trip->delete_trip();
        state = FINISHED;
        trip = NULL;
        cout << SUCCESS_MESSAGE << endl;
    }
    else
        throw logic_error(PERMISSION_DENIED_ERROR);
}
