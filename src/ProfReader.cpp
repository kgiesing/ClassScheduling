#include "../include/ProfReader.h"
#include <set>

using std::set;
using std::string;
using std::vector;

vector<Prof> ProfReader::read()
{
    ifstream file;
    string id;
    string fname;
    string lname;
    set<string> ids;
    set<Prof> profs;

    file.open(this->getFilename().c_str());
    if (!file.is_open())
        throw runtime_error("Could not open file: " + this->getFilename());
    while (!file.eof())
    {
        getline(file, id, this->getDelimiter());
        // Skip blank lines
        if (id.empty())
            continue;
        getline(file, lname, this->getDelimiter());
        getline(file, fname,  '\n');
        // Construct the object, add it to the set
        Prof p(id, fname, lname);
        if (ids.find(id) == ids.end())
        {
            profs.insert(p);
            ids.insert(id);
        }
    }
    file.close();
    // Convert to vector and return
    vector<Prof> output(profs.begin(), profs.end());
    return output;
}

