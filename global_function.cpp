#include "global_function.hpp"
using namespace std;
vector<string> split_by_space(string line)
{
    string space_delimiter = SPACE_DELIMITER;
    vector<string> words{};

    size_t pos = 0;
    while ((pos = line.find(space_delimiter)) != string::npos)
    {
        words.push_back(line.substr(0, pos));
        line = line.substr(pos + space_delimiter.length());
    }
    words.push_back(line);
    return words;
}