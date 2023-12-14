#include "trip.hpp"
#include "passenger.hpp"
#include "driver.hpp"
Trip::Trip(Person *_passengers, Location *_origin, Location *_destination, int _id)
{
    passenger = _passengers;
    origin = _origin;
    destination = _destination;
    id = _id;
    state = WAITING;
}

bool Trip::has_same_id_with(int _id)
{
    if (id == _id)
        return true;
    return false;
}

void Trip::change_info_after_accept(Person *_driver)
{
    if (state != WAITING)
        throw std::logic_error(BAD_REQUEST_ERROR);
    state = TRAVELING;
    passenger->change_info_after_accept();
}

void Trip::change_info_after_finish()
{
    state = FINISHED;
    passenger->change_info_after_finish();
}

void Trip::show_trip_info()
{
    std::map<int, std::string> maping_function;
    maping_function[0] = WAITING_STATUS;
    maping_function[1] = TRAVELING_STATUS;
    maping_function[2] = FINISHED_STATUS;
    std::cout << id << " " << passenger->get_name() << " " << origin->get_name() << " " << destination->get_name() << " " << maping_function[state] << std::endl;
}

bool Trip::is_cancelled()
{
    if (state == DELETED)
        return true;
    return false;
}

bool Trip::operator==(const Trip &trip)
{
    return id == trip.id;
}

void Trip::delete_trip()
{
    if (state == WAITING)
    {
        state = DELETED;
    }
    else
        throw std::logic_error(BAD_REQUEST_ERROR);
}