#ifndef __DEFINE_HPP__
#define __DEFINE_HPP__
#include <string>
enum State
{
    WAITING,
    TRAVELING,
    FINISHED,
    DELETED
};
const char LOCATION_DATA_DELIMITER = ',';
const std::string Gett = "GET";
const std::string Postt = "POST";
const std::string WAITING_STATUS = "waiting";
const std::string TRAVELING_STATUS = "traveling";
const std::string FINISHED_STATUS = "finished";
const std::string EMPTY_STRING = "";
const std::string DELETE = "DELETE";
const std::string SIGNUP = "signup";
const std::string COST = "cost";
const std::string IN_HURRY = "in_hurry";
const std::string TRIPS = "trips";
const std::string YES = "yes";
const std::string NO = "no";
const std::string SORT_BY_COST = "sort_by_cost";
const std::string COMMAND_DELIMITER = " ";
const std::string ACCEPT = "accept";
const std::string FINISH = "finish";
const std::string DRIVER = "driver";
const std::string PASSENGER = "passenger";
const std::string SUCCESS_MESSAGE = "OK";
const std::string BAD_REQUEST_ERROR = "Bad Request";
const std::string NOT_FOUND_ERROR = "Not Found";
const std::string PERMISSION_DENIED_ERROR = "Permission Denied";
const std::string USERNAME = "username";
const std::string ID = "id";
const std::string ROLE = "role";
const std::string ORIGIN = "origin";
const std::string SPACE_DELIMITER = " ";
const std::string DESTINATION = "destination";
const std::string EMPTY_LIST_ERROR = "Empty";
#endif