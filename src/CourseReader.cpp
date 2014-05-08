#include "../include/CourseReader.h"
#include <iostream> // for cerr
#include <fstream>
#include <set>
#include <sstream>

using std::cerr;
using std::endl;
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
    set<string> conflicts;
    set<Course> courses;

    file.open(this->getFilename().c_str());
    if (!file.is_open())
    {
        cerr << "Could not open file: " << this->getFilename() << endl;
        return vector<Course>();
    }
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
            conflicts.insert(conflict);
        }
        // Construct the object, add it to the set
        Course c(id, name, enrolled, profId, conflicts);
        courses.insert(c);
    }
    file.close();

    // Convert to vector sorted in descending order
    vector<Course> output(courses.size());
    set<Course>::reverse_iterator rev;
    for (rev = courses.rbegin(); rev != courses.rend(); ++rev)
        output.push_back(*rev);
    return output;
}
