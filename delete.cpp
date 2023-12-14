#include "delete.hpp"
Delete::Delete(std::string _command) : Request(_command) {}

void Delete::handle_request(Data &data)
{
    std::vector<std::string> requests = split_by_space(command);
    if (requests[0] == TRIPS)
        delete_trip(data, requests);
    else
        throw std::logic_error(NOT_FOUND_ERROR);
}

void Delete::delete_trip(Data &data, std::vector<std::string> commands)
{
    std::string username = find_next_word(commands, USERNAME);
    std::string _id = find_next_word(commands, ID);
    int id;
    if (username == EMPTY_STRING || _id == EMPTY_STRING)
        throw std::logic_error(BAD_REQUEST_ERROR);

    id = stoi(_id);
    data.delete_trip(username, id);
}