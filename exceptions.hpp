#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include "define.hpp"
class NotFound : public std::exception
{
    public:
    const char *what() const throw()
    {
        return "Not Found";
    }
};
class BadRequest : public std::exception
{
    public:
    const char *what() const throw()
    {
        return "Bad Request";
    }
};
class PermissionDenied : public std::exception
{
    public:
    const char *what() const throw()
    {
        return "Permission Denied";
    }
};

#endif