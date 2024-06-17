#include "post.hpp"
using namespace std;

void PostRequest::signup(Data &_data, const vector<string> &commands)
{
    string username, role;
    username = find_next_word(commands, USERNAME);
    role = find_next_word(commands, ROLE);
    if (username == EMPTY_STRING || role == EMPTY_STRING)
        throw BadRequest();

    if (role == DRIVER)
        _data.add_user(new Driver(username));
    else if (role == PASSENGER)
        _data.add_user(new Passenger(username));
    else
        throw BadRequest();
}

void PostRequest::trip(Data &data, const vector<string> &commands)
{
    bool in_hurry_;
    string username, destination, origin, in_hurry;
    username = find_next_word(commands, USERNAME);
    origin = find_next_word(commands, ORIGIN);
    destination = find_next_word(commands, DESTINATION);
    in_hurry = find_next_word(commands, IN_HURRY);
    int id = data.post_trip(username, origin, destination, in_hurry);
}

void PostRequest::accept(Data &data, const vector<string> &commands)
{
    int id;
    string _id;
    string username;
    username = find_next_word(commands, USERNAME);
    _id = find_next_word(commands, ID);
    if (username == EMPTY_STRING || _id == EMPTY_STRING)
        throw BadRequest();
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
        throw BadRequest();
    int id = stoi(_id);
    data.finish_a_trip(username, id);
}