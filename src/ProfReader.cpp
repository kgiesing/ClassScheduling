#include "../include/ProfReader.h"
#include <iostream> // for cerr
#include <fstream>
#include <set>

using std::cerr;
using std::endl;
using std::ifstream;
using std::set;
using std::string;
using std::vector;

vector<Prof> ProfReader::read()
{
    ifstream file;
    string id;
    string fname;
    string lname;
    set<Prof> profs;

    file.open(this->getFilename().c_str());
    if (!file.is_open())
    {
        cerr << "Could not open file: " << this->getFilename() << endl;
        return vector<Prof>();
    }
    while (!file.eof())
    {
        getline(file, id, this->getDelimiter());
        getline(file, lname, this->getDelimiter());
        getline(file, fname);
        // Construct the object, add it to the set
        Prof p(id, fname, lname);
        profs.insert(p);
    }
    file.close();
    // Convert to vector and return
    vector<Prof> output(profs.begin(), profs.end());
    return output;
}

