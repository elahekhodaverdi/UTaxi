#include "data.hpp"
using namespace std;

void Data::add_location(Location *_location)
{
    locations.push_back(_location);
}

void Data::add_user(Person *_person)
{
    if (!user_already_exists(_person))
    {
        users.push_back(_person);
        cout << SUCCESS_MESSAGE << endl;
    }
    else
        throw logic_error(BAD_REQUEST_ERROR);
}

bool Data::user_already_exists(Person *_person)
{
    for (auto &user : users)
    {
        if (_person->get_name() == user->get_name())
            return true;
    }
    return false;
}

void Data::post_trip(string username, string origin, string destination)
{
    Location *_origin = find_location(origin);
    Location *_destination = find_location(destination);
    Person *user = find_user(username);
    int id = trips.size() + 1;
    Trip *trip = new Trip(user, _origin, _destination, id);
    user->add_trip_for_post(trip);
    trips.push_back(trip);
    cout << id << endl;
}

Location *Data::find_location(string name)
{
    for (int i = 0; i < locations.size(); i++)
    {
        if (locations[i]->get_name() == name)
        {
            return locations[i];
        }
    }
    throw logic_error(NOT_FOUND_ERROR);
}

Person *Data::find_user(string name)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->get_name() == name)
        {
            return users[i];
        }
    }
    throw logic_error(NOT_FOUND_ERROR);
}

void Data::accept(string username, int id)
{
    Person *user = find_user(username);
    Trip *trip = find_trip(id);
    if (trip->is_cancelled())
        throw logic_error(NOT_FOUND_ERROR);
    user->accept_trip(trip);
}

Trip *Data::find_trip(int _id)
{
    for (auto &trip : trips)
    {
        if (trip->has_same_id_with(_id))
        {
            return trip;
        }
    }
    throw logic_error(NOT_FOUND_ERROR);
}

void Data::finish_a_trip(string username, int id)
{
    Person *user = find_user(username);
    Trip *trip = find_trip(id);
    user->finish_trip(trip);
}

void Data::show_trip_info(string username, int id)
{
    Person *user = find_user(username);
    Trip *trip = find_trip(id);
    if (trip->is_cancelled())
        throw logic_error(NOT_FOUND_ERROR);
    user->show_trip_info(trip);
}

void Data::show_trips(string username)
{
    Person *user = find_user(username);
    Driver *driver = dynamic_cast<Driver *>(user);
    if (driver == NULL)
        throw logic_error(PERMISSION_DENIED_ERROR);
    if (is_available_any_trip())
    {
        for (auto &trip : trips)
        {
            if (!trip->is_cancelled())
                trip->show_trip_info();
        }
    }
    else
        cout << EMPTY_LIST_ERROR << endl;
}

void Data::delete_trip(string username, int id)
{
    Person *user = find_user(username);
    Trip *trip = find_trip(id);
    user->delete_trip(trip);
}

bool Data::is_available_any_trip()
{
    if (trips.size() > 0)
    {
        for (auto &trip : trips)
        {
            if (!trip->is_cancelled())
                return true;
        }
    }
    return false;
}