#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "define.hpp"
#include "utaxi.hpp"
#include <iomanip>
using namespace std;



int main(int ardc, char* argv[])
{
    cout << setprecision(2) << fixed;
    Utaxi utaxi;
    utaxi.process((argv[1]));
    
}
