#include "person.hpp"
#include "data.hpp"
Person::Person(std::string _name)
{
    name = _name;
    state = FINISHED;
}

std::string Person::get_name()
{
    return name;
}
void Person::change_info_after_accept()
{
    state = TRAVELING;
}

void Person::change_info_after_finish()
{
    state = FINISHED;
    trip = nullptr;
}