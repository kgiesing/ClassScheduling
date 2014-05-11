#include "../include/VectorPrinter.h"
#include "../include/ObjectPrinter.h"

using std::endl;

void VectorPrinter::print(const vector<Course>& vec, string prefix,
                          ostream& out)
{
    if (vec.size() == 0)
    {
        out << prefix << "<empty>";
        return;
    }
    for(unsigned i = 0; i < vec.size(); i++)
    {
        ObjectPrinter::print(vec[i], prefix, out);
    }
    out << endl;
}

void VectorPrinter::print(const vector<Prof>& vec, string prefix,
                          ostream& out)
{
    if (vec.size() == 0)
    {
        out << prefix << "<empty>";
        return;
    }
    for(unsigned i = 0; i < vec.size(); i++)
    {
        ObjectPrinter::print(vec[i], prefix, out);
    }
    out << endl;
}

void VectorPrinter::print(const vector<ProfInfo>& vec, string prefix,
                          ostream& out)
{
    if (vec.size() == 0)
    {
        out << prefix << "<empty>";
        return;
    }
    for(unsigned i = 0; i < vec.size(); i++)
    {
        ObjectPrinter::print(vec[i], prefix, out);
    }
    out << endl;
}

void VectorPrinter::print(const vector<Room>& vec, string prefix,
                          ostream& out)
{
    if (vec.size() == 0)
    {
        out << prefix << "<empty>";
        return;
    }
    for(unsigned i = 0; i < vec.size(); i++)
    {
        ObjectPrinter::print(vec[i], prefix, out);
    }
    out << endl;
}
void VectorPrinter::print(const vector<TimeBlock>& vec, string prefix,
                          ostream& out)
{
    if (vec.size() == 0)
    {
        out << prefix << "<empty>";
        return;
    }
    out << prefix << "TimeBlock: {";
    for(unsigned i = 0; i < vec.size(); i++)
    {
        ObjectPrinter::print(vec[i], prefix, out);
        if (i < vec.size() - 1)
            out << ", ";
    }
    out << "}" << endl;
}

void VectorPrinter::print(const vector<Weekdays>& vec, string prefix,
                          ostream& out)
{
    if (vec.size() == 0)
    {
        out << prefix << "<empty>";
        return;
    }
    out << prefix << "Weekdays: {";
    for(unsigned i = 0; i < vec.size(); i++)
    {
        ObjectPrinter::print(vec[i], prefix, out);
        if (i < vec.size() - 1)
            out << ", ";
    }
    out << "}" << endl;
}

