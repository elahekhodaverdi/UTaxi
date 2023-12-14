#ifndef __UTAXI_HPP__
#define __UTAXI_HPP__
#include <iostream>
#include <vector>
#include <fstream>
#include "trip.hpp"
#include "passenger.hpp"
#include "driver.hpp"
#include "location.hpp"
#include "inputmanager.hpp"
#include "delete.hpp"
#include "post.hpp"
#include "get.hpp"
#include "data.hpp"
class Utaxi
{
public:
    void process(char *);

private:
    Data data;
    InputManager input_output;
    Request *request;
};
#endif /* __UTAXI_HPP__ */