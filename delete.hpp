#ifndef __DELETE_HPP__
#define __DELETE_HPP__
#include "requestt.hpp"
#include "data.hpp"
#include "exceptions.hpp"
class Delete : public Requestt
{
public:
    void delete_trip(Data &data, std::vector<std::string> commands);
};
#endif
