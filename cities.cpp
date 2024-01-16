// program to find how many cities are listed in a file based on command-line arguments
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main (int argc, char const *argv[])
{
    ifstream cities("cities.txt");   // opens file
    
    string state, city;
    multimap<string, string> locations; // creates a multimap with mappings made up of strings

    while (!cities.eof())
    {
        getline (cities, state, ',');   // reads each line in .txt while ignoring any commas
        getline (cities, city);
        locations.insert({state, city});    // inserts elements to multimap
    }

    for (int i = 1; i < argc; ++i)
        { cout << locations.count(argv[i]) << endl; }   // loops until all command-line arguments are used | counting how many times a key is used in a multimap

    return 0;
}
