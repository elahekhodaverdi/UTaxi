#include "delete.hpp"


void Delete::delete_trip(Data &data, std::vector<std::string> commands)
{
    std::string username = find_next_word(commands, USERNAME);
    std::string _id = find_next_word(commands, ID);
    int id;
    if (username == EMPTY_STRING || _id == EMPTY_STRING)
        throw BadRequest();

    id = stoi(_id);
    data.delete_trip(username, id);
}