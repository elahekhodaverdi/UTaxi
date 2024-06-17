#ifndef __HANDLER_HPP__
#define __HANDLER_HPP__
#include "server.hpp"
#include <string>
#include "../define.hpp"
#include "../post.hpp"
#include "../get.hpp"
#include "../delete.hpp"
#include <map>
#include <iomanip>
#include <sstream>
class Data;
class SignUpHandler : public RequestHandler
{
public:
    SignUpHandler(Data *_data);
    Response *callback(Request *);

private:
    Data *data;
};
class GetCostHandler : public TemplateHandler
{
public:
    GetCostHandler(Data *_data, std::string filePath);
    std::map<std::string, std::string> handle(Request *);

private:
    Data *data;
};

class PostTripHandler : public TemplateHandler
{
public:
    PostTripHandler(Data *_data, std::string filePath);
    std::map<std::string, std::string> handle(Request *);

private:
    Data *data;
};

class GetTripsHandler : public RequestHandler
{
public:
    GetTripsHandler(Data *_data);
    Response *callback(Request *);

private:
    Data *data;
};

class FinishHandler : public RequestHandler
{
public:
    FinishHandler(Data *_data);
    Response *callback(Request *);

private:
    Data *data;
};

class AcceptHandler : public RequestHandler
{
public:
    AcceptHandler(Data *_data);
    Response *callback(Request *);

private:
    Data *data;
};
class DeleteHandler : public RequestHandler
{
public:
    DeleteHandler(Data *_data);
    Response *callback(Request *);

private:
    Data *data;
};
class ResponseHandler : public TemplateHandler
{
public:
    ResponseHandler(std::string filePath, std::string message);
    std::map<std::string, std::string> handle(Request *);

private:
    std::string message;
};

#endif // __HANDLER_HPP__
