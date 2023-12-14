#include "inputmanager.hpp"
using namespace std;
void InputManager::read_location_data_file(Data &data, char *filename)
{
    ifstream location_file;
    location_file.open(filename);
    std::string line;
    getline(location_file, line);
    while (location_file >> line)
    {
        string name;
        double latitude, longitude;
        size_t index = line.find(LOCATION_DATA_DELIMITER);
        name = line.substr(0, index);
        line = line.substr(index + 1);
        index = line.find(LOCATION_DATA_DELIMITER);
        latitude = stod(line.substr(0, index));
        line = line.substr(index + 1);
        longitude = stod(line);
        data.add_location(new Location(name, latitude, longitude));
    }
    location_file.close();
}

Request *InputManager::get_command(string command)
{

    vector<string> request = split_by_space(command);
    size_t index = command.find(COMMAND_DELIMITER);
    string type = command.substr(0, index);

    if (type == GET)
        return new GetRequest(command.substr(GET.length()));
    else if (type == POST)
        return new PostRequest(command.substr(POST.length()));
    else if (type == DELETE)
        return new Delete(command.substr(DELETE.length()));
    else
        throw logic_error(BAD_REQUEST_ERROR);
}