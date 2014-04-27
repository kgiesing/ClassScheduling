#include "../include/CourseReader.h"
#include <fstream>
#include <set>
#include <sstream>

using std::ifstream;
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
    string conflict;
    vector<string> conflicts;
    set<Course> courses;

    file.open(this->getFilename().c_str());
    while (!file.eof())
    {
        getline(file, id, this->getDelimiter());
        getline(file, name, this->getDelimiter());
        getline(file, profId, this->getDelimiter());
        // Stream enrolled to int, then discard chars before delimiter
        file >> enrolled;
        getline(file, temp, this->getDelimiter());
        // The rest of the values until end-of-line are conflicts
        getline(file, temp);
        stringstream ss(temp);
        while (!ss.eof()) {
            getline(ss, conflict, this->getDelimiter());
            conflicts.push_back(conflict);
        }
        // Construct the object, add it to the set
        Course c(id, name, enrolled, profId, conflicts);
        courses.insert(c);
    }
    // Convert to vector and return
    vector<Course> output(courses.begin(), courses.end());
    return output;
}
