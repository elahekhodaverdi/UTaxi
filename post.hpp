#ifndef __POST_HPP__
#define __POST_HPP__
#include "request.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>
#include <string>
#include "driver.hpp"
#include "passenger.hpp"
class PostRequest : public Request
{
public:
    PostRequest(std::string _command);
    void handle_request(Data &_data);
    void signup(Data &_data, const std::vector<std::string> &commands);
    void trip(Data &_data, const std::vector<std::string> &commands);
    void accept(Data &data, const std::vector<std::string> &commands);
    void finish(Data &data, const std::vector<std::string> &commands);

private:
};
#endif
