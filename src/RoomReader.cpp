#include "../include/RoomReader.h"
#include <iostream> // for cerr
#include <fstream>
#include <set>

using std::cerr;
using std::endl;
using std::ifstream;
using std::set;
using std::string;
using std::vector;

vector<Room> RoomReader::read()
{
    ifstream file;
    string id;
    string temp;
    int capacity;
    set<string> ids;
    set<Room> rooms;

    file.open(this->getFilename().c_str());
    if (!file.is_open())
    {
        cerr << "Could not open file: " << this->getFilename() << endl;
        return vector<Room>();
    }
    while (!file.eof())
    {
        getline(file, id, this->getDelimiter());
        // Skip blank lines
        if (id.empty())
            continue;
        // Stream capacity as int, then discard chars before newline
        capacity = 0;
        file >> capacity;
        getline(file, temp, '\n');
        // Construct the object, add it to the set
        Room r(id, capacity);
        if (ids.find(id) == ids.end())
        {
            rooms.insert(r);
            ids.insert(id);
        }
    }
    file.close();

    // Convert to vector sorted in descending order
    vector<Room> output(rooms.rbegin(), rooms.rend());
    return output;
}

