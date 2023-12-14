#ifndef __REQUEST_HPP__
#define __REQUEST_HPP__
#include <string>
#include "data.hpp"
#include <algorithm>
#include <exception>
#include <iostream>
#include "global_function.hpp"
#include "define.hpp"
class Request
{
public:
    Request(std::string _command);
    virtual void handle_request(Data &_data) = 0;
    std::string find_next_word(const std::vector<std::string> &request, std::string _given_word);

protected:
    std::string command;
};
#endif
