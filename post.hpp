#ifndef __POST_HPP__
#define __POST_HPP__
#include "requestt.hpp"
#include <iostream>
#include <stdexcept>
#include "exceptions.hpp"
#include <string>
#include "driver.hpp"
#include "passenger.hpp"
class PostRequest : public Requestt
{
public:
    void signup(Data &_data, const std::vector<std::string> &commands);
    void trip(Data &_data, const std::vector<std::string> &commands);
    void accept(Data &data, const std::vector<std::string> &commands);
    void finish(Data &data, const std::vector<std::string> &commands);

private:
};
#endif
