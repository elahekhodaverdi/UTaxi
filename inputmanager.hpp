#ifndef __IO_HPP__
#define __IO_HPP__
#include <iostream>
#include "data.hpp"
#include <fstream>
#include <string>
#include <vector>
#include "define.hpp"
#include "request.hpp"
#include "post.hpp"
#include "get.hpp"
#include "delete.hpp"

#include "global_function.hpp"
class InputManager
{
public:
    void read_location_data_file(Data &data, char *filename);
    Request *get_command(std::string);

private:
};
#endif
