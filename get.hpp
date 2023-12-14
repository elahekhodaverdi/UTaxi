#ifndef __GET_HPP__
#define __GET_HPP__
#include "request.hpp"
#include <string>
class GetRequest : public Request
{
public:
    GetRequest(std::string _command);
    void handle_request(Data &_data);
    void trip(Data &data, std::vector<std::string> &_commands);
    void show_trip_info(Data &data, std::vector<std::string> &_commands);
    void show_trips(Data &data, std::vector<std::string> &_commands);

private:
};
#endif
