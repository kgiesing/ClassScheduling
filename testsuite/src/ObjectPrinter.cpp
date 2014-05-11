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

void ObjectPrinter::print(TimeBlock t, string prefix, ostream& out)
{
    switch(t)
    {
    case START_08_00:
        out << "8:00am-9:15am";
        break;
    case START_09_30:
        out << "9:30am-10:45am";
        break;
    case START_11_00:
        out << "11:00am-12:15pm";
        break;
    case START_12_30:
        out << "12:30pm-1:45pm";
        break;
    case START_14_00:
        out << "2:00pm-3:15pm";
        break;
    case START_15_30:
        out << "3:30pm-4:45pm";
        break;
    case START_17_00:
        out << "5:00pm-6:15pm";
        break;
    case START_18_30:
        out << "6:30pm-7:45pm";
        break;
    case START_20_00:
        out << "8:00pm-9:15pm";
        break;
    case TIMEBLOCK_SIZE:    //shouldn't get here!
        out << "SIZE";
    }
}

void ObjectPrinter::print(Weekdays w, string prefix, ostream& out)
{
    switch(w)
    {
    case MON:
        out << "Monday";
        break;
    case TUES:
        out << "Tuesday";
        break;
    case WED:
        out << "Wednesday";
        break;
    case THURS:
        out << "Thursday";
        break;
    case FRI:
        out << "Friday";
        break;
    case WEEKDAYS_SIZE:
        out << "SIZE";
    }
}

