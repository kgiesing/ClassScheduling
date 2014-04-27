#include "../include/RoomReader.h"
#include <fstream>
#include <set>

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
    set<Room> rooms;

    file.open(this->getFilename().c_str());
    while (!file.eof())
    {
        getline(file, id, this->getDelimiter());
        // Stream capacity as int, then discard chars before newline
        file >> capacity;
        getline(file, temp);
        // Construct the object, add it to the set
        Room r(id, capacity);
        rooms.insert(r);
    }
    file.close();

    // Convert to vector and return
    vector<Room> output(rooms.begin(), rooms.end());
    return output;
}

