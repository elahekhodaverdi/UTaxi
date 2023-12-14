#include "utaxi.hpp"
using namespace std;
void Utaxi::process(char *filename)
{
    input_output.read_location_data_file(data, filename);
    string command;
    while (getline(cin, command))
    {
        try
        {
            request = input_output.get_command(command);
            request->handle_request(data);
        }
        catch (logic_error &ex)
        {
            cout << ex.what() << endl;
        }
    }
}