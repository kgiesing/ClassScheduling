#include "../include/CourseReader.h"
#include <map>
#include <set>
#include <sstream>

using std::map;
using std::set;
using std::string;
using std::stringstream;
using std::vector;

vector<Course> CourseReader::read()
{
    ifstream file;
    string id;
    string name;
    string profId;
    string temp;
    int enrolled;
    int timeBlocks;
    string conflict;
    set<string> conflicts;
    set<string> ids;
    set<Course> courses;

    file.open(this->getFilename().c_str());
    if (!file.is_open())
        throw runtime_error("Could not open file: " + this->getFilename());
    while (!file.eof())
    {
        getline(file, id, this->getDelimiter());
        // Skip blank lines
        if (id.empty())
            continue;
        getline(file, name, this->getDelimiter());
        getline(file, profId, this->getDelimiter());
        // Stream enrolled to int, then discard chars before delimiter
        enrolled = 0;
        file >> enrolled;
        getline(file, temp, this->getDelimiter());
        // Stream timeBlocks to int, then discard chars before delimiter
        file >> timeBlocks;
        getline(file, temp, this->getDelimiter());
        // The rest of the values until end-of-line are conflicts
        conflicts.clear();
        getline(file, temp, '\n');
        stringstream ss(temp);
        while (!ss.eof()) {
            getline(ss, conflict, this->getDelimiter());
            if (!conflict.empty())
                conflicts.insert(conflict);
        }
        // Construct the object, add it to the set
        Course c(id, name, profId, enrolled, timeBlocks, conflicts);
        if (ids.find(id) == ids.end())
        {
            courses.insert(c);
            ids.insert(id);
        }
    }
    file.close();

    // Convert to vector sorted in descending order
    vector<Course> output(courses.rbegin(), courses.rend());
    return output;
}
