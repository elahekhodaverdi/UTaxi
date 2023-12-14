#include "global_function.hpp"
using namespace std;
vector<string> split_by_space(string line)
{
    string space_delimiter = " ";
    vector<string> words{};

    size_t pos = 0;
    while ((pos = line.find(space_delimiter)) != string::npos)
    {
        words.push_back(line.substr(0, pos));
        line = line.substr(pos + space_delimiter.length());
    }
    words.push_back(line);
    words.erase(words.begin());
    return words;
}