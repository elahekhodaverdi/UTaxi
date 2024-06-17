#include "requestt.hpp"
// Requestt::Requestt(std::string _command)
// {
//     command = _command;
// }

std::string Requestt::find_next_word(const std::vector<std::string> &request, std::string _given_word)
{
    for (int i = 0; i < request.size() - 1; i++)
    {
        if (request[i] == _given_word)
        {
            return request[i + 1];
        }
    }
    return EMPTY_STRING;
}
