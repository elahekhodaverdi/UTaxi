#include "post.hpp"
using namespace std;
PostRequest::PostRequest(string _command) : Request(_command) {}

void PostRequest::handle_request(Data &_data)
{
    vector<string> requests = split_by_space(command);
    if (requests[0] == SIGNUP)
        signup(_data, requests);
    else if (requests[0] == TRIPS)
        trip(_data, requests);
    else if (requests[0] == ACCEPT)
        accept(_data, requests);
    else if (requests[0] == FINISH)
        finish(_data, requests);
    else
        throw logic_error(NOT_FOUND_ERROR);
}

void PostRequest::signup(Data &_data, const vector<string> &commands)
{
    string username, role;
    username = find_next_word(commands, USERNAME);
    role = find_next_word(commands, ROLE);
    if (username == EMPTY_STRING || role == EMPTY_STRING)
        throw logic_error(BAD_REQUEST_ERROR);

    if (role == DRIVER)
        _data.add_user(new Driver(username));
    else if (role == PASSENGER)
        _data.add_user(new Passenger(username));
    else
        throw logic_error(BAD_REQUEST_ERROR);
}

void PostRequest::trip(Data &_data, const vector<string> &commands)
{
    string username, destination, origin;
    username = find_next_word(commands, USERNAME);
    origin = find_next_word(commands, ORIGIN);
    destination = find_next_word(commands, DESTINATION);
    if (username == EMPTY_STRING || destination == EMPTY_STRING || origin == EMPTY_STRING)
        throw logic_error(BAD_REQUEST_ERROR);

    _data.post_trip(username, origin, destination);
}

void PostRequest::accept(Data &data, const vector<string> &commands)
{
    int id;
    string _id;
    string username;
    username = find_next_word(commands, USERNAME);
    _id = find_next_word(commands, ID);
    if (username == EMPTY_STRING || _id == EMPTY_STRING)
        throw logic_error(BAD_REQUEST_ERROR);
    id = stoi(_id);
    data.accept(username, id);
}

void PostRequest::finish(Data &data, const vector<string> &commands)
{
    string username;
    string _id;
    username = find_next_word(commands, USERNAME);
    _id = find_next_word(commands, ID);
    if (username == EMPTY_STRING || _id == EMPTY_STRING)
        throw logic_error(BAD_REQUEST_ERROR);
    int id = stoi(_id);
    data.finish_a_trip(username, id);
}