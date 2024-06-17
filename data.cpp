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
    }
    else
    {
        throw BadRequest();
    }
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

int Data::post_trip(string username, string _origin, string _destination, string _in_hurry)
{
    if (username == EMPTY_STRING || _destination == EMPTY_STRING || _origin == EMPTY_STRING || _in_hurry == EMPTY_STRING)
        throw BadRequest();
    bool in_hurry = (_in_hurry == YES) ? true : false;
    Location *origin = find_location(_origin);
    Location *destination = find_location(_destination);
    Person *user = find_user(username);
    int id = trips.size() + 1;
    Trip *trip = new Trip(user, origin, destination, id, in_hurry);
    user->add_trip_for_post(trip);
    trips.push_back(trip);
    return id;
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
    throw NotFound();
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
    throw NotFound();
}

void Data::accept(string username, int id)
{
    Person *user = find_user(username);
    Trip *trip = find_trip(id);
    if (trip->is_cancelled())
        throw NotFound();
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
    throw NotFound();
}

void Data::finish_a_trip(string username, int id)
{
    Person *user = find_user(username);
    Trip *trip = find_trip(id);
    user->finish_trip(trip);
}

Trip *Data::show_trip_info(string username, int id)
{
    Person *user = find_user(username);
    Trip *trip = find_trip(id);
    if (trip->is_cancelled())
        throw NotFound();
    return user->show_trip_info(trip);
}

vector<Trip *> Data::show_trips(string username, bool sort_by_cost)
{
    Person *user = find_user(username);
    Driver *driver = dynamic_cast<Driver *>(user);
    vector<Trip *> results;
    if (driver == NULL)
        throw PermissionDenied();
    if (is_available_any_trip())
    {
        vector<Trip *> copy_trips = trips;
        if (sort_by_cost)
            sort(copy_trips.begin(), copy_trips.end(), compare_trips_cost);

        for (auto &trip : copy_trips)
            if (!trip->is_cancelled())
                results.push_back(trip);
        return results;
    }
    else
        return results;
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

double Data::get_cost(std::string username, std::string _origin, std::string _destination, std::string in_hurry)
{
    if (username == EMPTY_STRING || _destination == EMPTY_STRING || _origin == EMPTY_STRING || in_hurry == EMPTY_STRING)
        throw BadRequest();
    Location *origin = find_location(_origin);
    Location *destination = find_location(_destination);
    Person *user = find_user(username);
    return user->get_cost_trip(origin, destination, in_hurry);
}

void Data::print_trips(bool sort_by_cost)
{
    vector<Trip *> copy_trips = trips;
    if (sort_by_cost)
        sort(copy_trips.begin(), copy_trips.end(), compare_trips_cost);

    for (auto &trip : copy_trips)
    {
        if (!trip->is_cancelled())
            trip->show_trip_info();
    }
}
bool compare_trips_cost(Trip *first, Trip *second)
{
    return (first->is_expensive_than(second));
}