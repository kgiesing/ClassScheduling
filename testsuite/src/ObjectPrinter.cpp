#include "ObjectPrinter.h"

using std::endl;

void ObjectPrinter::print(const Course& c, string prefix, ostream& out)
{
    out << prefix << "Course {ID:\"" << c.getId() << "\",\n"
        << prefix << "        Name:\""<< c.getName() << "\",\n"
        << prefix << "        Enrolled:"<< c.getEnrolled() << ",\n"
        << prefix << "        Prof ID:\""<< c.getProfId() << "\",\n"
        << prefix << "        Conflicts:";
    set<string> conflicts = c.getConflicts();
    set<string>::iterator it;
    for (it = conflicts.begin(); it != conflicts.end(); ++it)
        out << "\"" << (*it) << "\" ";
    out << endl << prefix << "       }\n";
}

void ObjectPrinter::print(const Prof& p, string prefix, ostream& out)
{
    out << prefix << "Prof {ID:" << p.getId()
        << ", First:"<< p.getFirstName()
        << ", Last:"<< p.getLastName()
        << "}\n";
}

void ObjectPrinter::print(const ProfInfo& pi, string prefix, ostream& out)
{
    out << prefix << "ProfInfo {DaysOnCampus:" << pi.getDaysOnCampus()
        << ", NumCourses:"<< pi.getNumCourses()
        << ", Score:"<< pi.getScore() << endl
        << prefix << "          getProf:";
    print(pi.getProf());
    out << prefix << "         }\n";
}

void ObjectPrinter::print(const Room& r, string prefix, ostream& out)
{
    out << prefix << "Room {ID:" << r.getId()
        << ", Capacity:"<< r.getCapacity()
        << "}\n";
}
