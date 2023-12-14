#ifndef __DELETE_HPP__
#define __DELETE_HPP__
#include "request.hpp"
#include "data.hpp"
class Delete : public Request
{
public:
    Delete(std::string);
    void handle_request(Data &data);
    void delete_trip(Data &data, std::vector<std::string> commands);
};
#endif
