#include "VectorPrinter.h"

using std::endl;

void VectorPrinter::print(const vector<Course>& courses, ostream& out)
{
    set<string>::iterator it;
    for(unsigned i = 0; i < courses.size(); i++)
    {
        out << "\n\tCourse: {ID:" << courses[i].getId() << ","
            << "\n\t         Name:"<< courses[i].getName() << ","
            << "\n\t         Enrolled:"<< courses[i].getEnrolled() << ","
            << "\n\t         Prof ID:"<< courses[i].getProfId() << ","
            << "\n\t         Conflicts:";
        set<string> conflicts = courses[i].getConflicts();
        for (it = conflicts.begin(); it != conflicts.end(); ++it)
            out << (*it) << " ";
        out << "\n\t        }";
    }
    out << endl;
}

void VectorPrinter::print(const vector<Prof>& profs, ostream& out)
{
    for(unsigned i = 0; i < profs.size(); i++)
    {
        out << "\n\tProf: {ID:" << profs[i].getId()
            << ", First:"<< profs[i].getFirstName()
            << ", Last:"<< profs[i].getLastName()
            << "}";
    }
    out << endl;
}

void VectorPrinter::print(const vector<Room>& rooms, ostream& out)
{
    for(unsigned i = 0; i < rooms.size(); i++)
    {
        out << "\n\tRoom: {ID:" << rooms[i].getId()
            << ", Capacity:"<< rooms[i].getCapacity()
            << "}";
    }
    out << endl;
}

