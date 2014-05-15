#include "../include/MapPrinter.h"
#include "../include/ObjectPrinter.h"

using std::endl;

void MapPrinter::print(const map<string, Course>& m, string prefix,
                          ostream& out)
{
    map<string, Course>::const_iterator it;
    out << "map<string -> Course>:" << endl;
    for (it = m.begin(); it != m.end(); it++)
    {
        out << prefix << "  \"" << it->first << "\"" << endl
            << prefix << "  -> ";
        ObjectPrinter::print(it->second, prefix, out);
    }
}

void MapPrinter::print(const map<string, Prof>& m, string prefix,
                          ostream& out)
{
    map<string, Prof>::const_iterator it;
    out << "map<string -> Prof>:" << endl;
    for (it = m.begin(); it != m.end(); it++)
    {
        out << prefix << "  \"" << it->first << "\" -> ";
        ObjectPrinter::print(it->second, prefix, out);
    }
}

void MapPrinter::print(const map<string, ProfInfo>& m, string prefix,
                          ostream& out)
{
    map<string, ProfInfo>::const_iterator it;
    out << "map<string -> ProfInfo>:" << endl;
    for (it = m.begin(); it != m.end(); it++)
    {
        out << prefix << "  \"" << it->first << "\"" << endl
            << prefix << "  -> ";
        ObjectPrinter::print(it->second, prefix, out);
    }
}

void MapPrinter::print(const map<string, ProfInfo*>& m, string prefix,
                          ostream& out)
{
    map<string, ProfInfo*>::const_iterator it;
    out << "map<string -> Prof>:" << endl;
    for (it = m.begin(); it != m.end(); it++)
    {
        out << prefix << "  \"" << it->first << "\" -> ";
        ObjectPrinter::print(*it->second, prefix, out);
    }
}

void MapPrinter::print(const map<string, Room>& m, string prefix,
                          ostream& out)
{
    map<string, Room>::const_iterator it;
    out << "map<string -> Room>:" << endl;
    for (it = m.begin(); it != m.end(); it++)
    {
        out << prefix << "  \"" << it->first << "\" -> ";
        ObjectPrinter::print(it->second, prefix, out);
    }
}

void MapPrinter::print(const map<string, TimeBlock>& m, string prefix,
                          ostream& out)
{
    map<string, TimeBlock>::const_iterator it;
    out << "map<string -> TimeBlock>:" << endl;
    for (it = m.begin(); it != m.end(); it++)
    {
        out << prefix << "  \"" << it->first << "\" -> ";
        ObjectPrinter::print(it->second, prefix, out);
    }
}

void MapPrinter::print(const map<string, Weekdays>& m, string prefix,
                          ostream& out)
{
    map<string, Weekdays>::const_iterator it;
    out << "map<string -> Weekdays>:" << endl;
    for (it = m.begin(); it != m.end(); it++)
    {
        out << prefix << "  \"" << it->first << "\" -> ";
        ObjectPrinter::print(it->second, prefix, out);
    }
}

