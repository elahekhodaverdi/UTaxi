#include "trip.hpp"
#include "passenger.hpp"
#include "driver.hpp"
using namespace std;
Trip::Trip(Person *_passengers, Location *_origin, Location *_destination, int _id, bool _in_hurry)
{
    passenger = _passengers;
    origin = _origin;
    destination = _destination;
    hurry = _in_hurry;
    if (hurry)
        cost = 1.2 * origin->cal_trip_cost(destination);
    else
        cost = origin->cal_trip_cost(destination);
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
        throw BadRequest();
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
    map<int, string> maping_function;
    maping_function[0] = WAITING_STATUS;
    maping_function[1] = TRAVELING_STATUS;
    maping_function[2] = FINISHED_STATUS;
    cout << id << SPACE_DELIMITER << passenger->get_name() << SPACE_DELIMITER << origin->get_name() << SPACE_DELIMITER << destination->get_name() << SPACE_DELIMITER;
    cout << cost;
    cout << SPACE_DELIMITER << maping_function[state] << endl;
}

bool Trip::is_cancelled()
{
    if (state == DELETED)
        return true;
    return false;
}

bool Trip::operator==(Trip *trip)
{
    if (!trip)
        return false;
    return id == trip->id;
}

void Trip::delete_trip()
{
    if (state == WAITING)
    {
        state = DELETED;
    }
    else
        throw BadRequest();
}
bool Trip::is_expensive_than(Trip *_trip)
{
    return cost > _trip->cost;
}

void Trip::complete_body_response(ostringstream &body, string username)
{
    map<State, string> maping_function;

    maping_function[WAITING] = WAITING_STATUS;
    maping_function[TRAVELING] = TRAVELING_STATUS;
    maping_function[FINISHED] = FINISHED_STATUS;
    body << "<tr>" << endl
         << "<td>" << id << "</td>" << endl
         << "<td>" << passenger->get_name() << "</td>" << endl
         << "<td>" << origin->get_name() << "</td>" << endl
         << "<td>" << destination->get_name() << "</td>" << endl
         << "<td>" << cost << "</td>" << endl
         << "<td>" << maping_function[state] << "</td>" << endl
         << "<form action='accept' method='post'>" << endl
         << "<input type='hidden' name='username' value='" << username << "' />" << endl
         << "<input type='hidden' name='id' value='" << id << "' />" << endl
         << "<td>"
         << "<input type='submit' value='  ' />"
         << "</td>" << endl
         << "<td>"
         << "<input type='submit' value='  ' formaction='finish' />"
         << "</td>" << endl
         << "</form>" << endl
         << "</tr" << endl;
}