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
        double latitude, longitude, traffic;
        size_t index = line.find(LOCATION_DATA_DELIMITER);
        name = line.substr(0, index);
        line = line.substr(index + 1);
        index = line.find(LOCATION_DATA_DELIMITER);
        latitude = stod(line.substr(0, index));
        line = line.substr(index + 1);
        index = line.find(LOCATION_DATA_DELIMITER);
        longitude = stod(line.substr(0, index));
        line = line.substr(index + 1);
        traffic = stod(line);
        data.add_location(new Location(name, latitude, longitude, traffic));
    }
    location_file.close();
}
