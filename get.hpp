#ifndef __GET_HPP__
#define __GET_HPP__
#include "requestt.hpp"
#include <vector>
#include <string>
#include "trip.hpp"
class GetRequest : public Requestt
{
public:
    std::vector<Trip*> trip(Data &data, std::vector<std::string> &);
    void show_trip_info(Data &data, std::vector<std::string> &);
    void get_cost(Data &data, std::vector<std::string> &);

private:
};
#endif
