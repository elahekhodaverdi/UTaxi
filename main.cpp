#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "define.hpp"
#include "utaxi.hpp"

using namespace std;



int main(int ardc, char* argv[])
{
    Utaxi utaxi;
    utaxi.process((argv[1]));
    
}
