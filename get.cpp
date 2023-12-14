#include "get.hpp"
GetRequest::GetRequest(std::string _command) : Request(_command)
{
}
void GetRequest::handle_request(Data &data)
{
    std::vector<std::string> requests = split_by_space(command);
    if (requests[0] == TRIPS)
        trip(data, requests);
    else
        throw std::logic_error(NOT_FOUND_ERROR);
}

void GetRequest::trip(Data &data, std::vector<std::string> &commands)
{
    std::string username = find_next_word(commands, USERNAME);
    std::string _id = find_next_word(commands, ID);
    int id;
    if (username != EMPTY_STRING)
    {
        if (_id != EMPTY_STRING)
        {
            id = stoi(_id);
            data.show_trip_info(username, id);
        }
        else
            data.show_trips(username);
    }
    else
        throw std::logic_error(BAD_REQUEST_ERROR);
}

void GetRequest::show_trip_info(Data &data, std::vector<std::string> &commands)
{
    std::string username = find_next_word(commands, USERNAME);
    int id = stoi(find_next_word(commands, ID));
    data.show_trip_info(username, id);
}

void GetRequest::show_trips(Data &data, std::vector<std::string> &commands)
{
    std::string username = find_next_word(commands, USERNAME);
}