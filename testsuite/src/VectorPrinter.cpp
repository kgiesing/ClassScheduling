#include "../include/VectorPrinter.h"
#include "../include/ObjectPrinter.h"

using std::endl;

void VectorPrinter::print(const vector<Course>& vec, string prefix, ostream& out)
{
    for(unsigned i = 0; i < vec.size(); i++)
    {
        ObjectPrinter::print(vec[i], prefix, out);
    }
    out << endl;
}

void VectorPrinter::print(const vector<Prof>& vec, string prefix, ostream& out)
{
    for(unsigned i = 0; i < vec.size(); i++)
    {
        ObjectPrinter::print(vec[i], prefix, out);
    }
    out << endl;
}

void VectorPrinter::print(const vector<ProfInfo>& vec, string prefix, ostream& out)
{
    for(unsigned i = 0; i < vec.size(); i++)
    {
        ObjectPrinter::print(vec[i], prefix, out);
    }
    out << endl;
}

void VectorPrinter::print(const vector<Room>& vec, string prefix, ostream& out)
{
    for(unsigned i = 0; i < vec.size(); i++)
    {
        ObjectPrinter::print(vec[i], prefix, out);
    }
    out << endl;
}

