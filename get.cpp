#include "get.hpp"
using namespace std;


vector<Trip *> GetRequest::trip(Data &data, vector<string> &commands)
{
    vector<Trip *> trips;
    string username = find_next_word(commands, USERNAME);
    string _id = find_next_word(commands, ID);
    string sort_by_cost_ = find_next_word(commands, SORT_BY_COST);
    bool sort_by_cost;
    int id;
    if (username != EMPTY_STRING)
    {
        if (_id != EMPTY_STRING)
        {
            id = stoi(_id);
            trips.push_back(data.show_trip_info(username, id));
            return trips;
        }
        else
        {
            if (sort_by_cost_ != EMPTY_STRING)
            {
                sort_by_cost = (sort_by_cost_ == YES) ? true : false;
                return data.show_trips(username, sort_by_cost);
            }
            else
            {
                throw BadRequest();
            }
        }
    }
    else
        throw BadRequest();
}

void GetRequest::show_trip_info(Data &data, vector<string> &commands)
{
    string username = find_next_word(commands, USERNAME);
    int id = stoi(find_next_word(commands, ID));
    data.show_trip_info(username, id);
}

void GetRequest::get_cost(Data &data, vector<string> &commands)
{
    string username = find_next_word(commands, USERNAME);
    string origin = find_next_word(commands, ORIGIN);
    string destination = find_next_word(commands, DESTINATION);
    string in_hurry = find_next_word(commands, IN_HURRY);
    if (username == EMPTY_STRING || destination == EMPTY_STRING || origin == EMPTY_STRING || in_hurry == EMPTY_STRING)
        throw BadRequest();
    data.get_cost(username, origin, destination, in_hurry);
}