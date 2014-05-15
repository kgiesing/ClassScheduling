#include "../include/DataCreator.h"
#include <cstdlib> // for random number generation
#include <ctime>   // for seeing generator with time
#include <fstream> // for creating files
#include <sstream> // for converting int to string

Course DataCreator::createCourse(void)
{
    Course c;
    string names[] = {"Art", "Biology", "Chemistry", "Computer Science",
            "Film", "Literature", "Mathematics", "Music", "Physics"};
    string abbrs[] = {"ART", "BIO", "CHEM", "CS", "FILM", "LIT", "MATH",
            "MUS", "PHYS"};
    string levels[] = {"Beginning", "Introductory", "Intermediate",
            "Advanced"};
    string nums[] = {"110", "220", "340", "440"};
    string profIds[] = {"12345678", "23456781", "34567812", "45678123",
            "56781234", "67812345", "78123456", "81234567"};
    // Generate random course
    int type = rand() % 9;
    int level = rand() % 4;

    c.setId(abbrs[type] + "-" + nums[level]);
    c.setName(levels[level] + " " + names[type]);
    // Note that there is NO guarantee that this Prof exists!
    c.setProfId(profIds[rand() % 8]);
    c.setEnrolled(rand() % 40);

    // Create some random conflicts
    set<string> conflicts;
    int numConflicts = rand() % 4;
    int newType = type;
    for (int i = 0; i < numConflicts; i++)
    {
        // Conflict is different course at same level
        // Note that there is NO guarantee that this Course exists!
        while (newType == type)
            newType = (type + rand()) % 9;
        conflicts.insert(abbrs[newType] + "-" + nums[level]);
    }
    c.setConflicts(conflicts);

    return c;
}

Prof DataCreator::createProf(void)
{
    string fnames[] = {"Alfred", "Bob", "Emily", "Lin", "Martin", "Mary",
            "Patricia", "Peter", "Ronald", "William"};
    string lnames[] = {"Campbell", "Chen", "Jackson", "Johnson", "Lee", "Nguyen",
            "Patel", "Rodriguez", "Singh", "Wong"};
    Prof p;
    // ID is simply an 8-digit number
    std::stringstream ss;
    ss << (rand() % 9999999) + 10000000 * (rand() % 9 + 1);
    p.setId(ss.str());
    // Randomly set first and last names
    p.setFirstName(fnames[rand() % 10]);
    p.setLastName(lnames[rand() % 10]);
    return p;
}

Room DataCreator::createRoom(void)
{
    string bldgs[] = {"M", "S", "W"};
    string floors[] = {"1", "2", "3", "4"};
    string rooms[] = {"01", "02", "03", "04", "05", "06", "07", "08", "09",
            "10"};
    Room r;
    // ID is derived from the above
    int floor = rand() % 4;
    string id = bldgs[rand() % 3] + "-" + floors[floor] + rooms[rand() % 10];
    // Capacity should be divisible by 5, and in range 20 - 100
    int capacity = 5 * (rand() % 16) + 20;
    // If it's on the ground floor, it may be a lecture hall; add 0 - 400
    if (floor == 0)
        capacity += (rand() % 4) * 100;
    r.setId(id);
    r.setCapacity(capacity);
    return r;
}

Schedule DataCreator::createSchedule(void)
{
    // Make sure there are few Courses and Profs, and lots of Rooms
    vector<Course> courses = DataCreator::createVector(DataCreator::createCourse(), 10);
    vector<Prof> profs = DataCreator::createVector(DataCreator::createProf(), 5);
    vector<Room> rooms = DataCreator::createVector(DataCreator::createRoom());
    DataCreator::loadProfs(courses, profs);

    // Create the Schedule object.
    Schedule s(rooms, profs, courses);

    // Go through the Courses, and schedule them.
    int day = 0;
    int time = 0;
    int idxRooms = 0;
    for (unsigned c = 0; c < courses.size(); c++)
    {
        bool ok = false;
        while (!ok)
        {
            int orig = idxRooms++;
            while (orig != idxRooms && rooms[idxRooms].getCapacity() < courses[c].getEnrolled())
                idxRooms = (idxRooms + 1) % rooms.size();
            if (orig == idxRooms) // Capacity is greater than any room
                courses[c].setEnrolled(1); // Set to minimum enrollment
            else
            {
                Weekdays wd = static_cast<Weekdays>(day);
                TimeBlock tb = static_cast<TimeBlock>(time);
                ok = s.setCourse(courses[c], rooms[idxRooms], wd, tb, courses[c].getTimeBlocks());
                time++;
                if (time >= TIMEBLOCK_SIZE)
                {
                    time = 0;
                    day = (day + 1) % WEEKDAYS_SIZE;
                }
            }
        }
    }
    return s;
}

vector<Course> DataCreator::createVector(Course type, int members)
{
    set<Course> sorted;
    srand(time(NULL) + rand() % 1000);
    int spread = members / 4;
    members += (rand() % spread) - spread / 2;
    for (int i = 0; i < members; i++)
        sorted.insert(createCourse());
    vector<Course> result(sorted.rbegin(), sorted.rend());
    return result;
}

vector<Prof> DataCreator::createVector(Prof type, int members)
{
    set<Prof> sorted;
    srand(time(NULL) + rand() % 1000);
    int spread = members / 4;
    members += (rand() % spread) - spread / 2;
    for (int i = 0; i < members; i++)
        sorted.insert(createProf());
    vector<Prof> result(sorted.begin(), sorted.end());
    return result;
}

vector<Room> DataCreator::createVector(Room type, int members)
{
    set<Room> sorted;
    srand(time(NULL) + rand() % 1000);
    int spread = members / 4;
    members += (rand() % spread) - spread / 2;
    for (int i = 0; i < members; i++)
        sorted.insert(createRoom());
    vector<Room> result(sorted.rbegin(), sorted.rend());
    return result;
}
bool DataCreator::createVectorFile(string filename, Course c, int members)
{
    std::ofstream out;
    out.open(filename.c_str());
    if (!out.is_open())
        return false;
    vector<Course> courses = createVector(c, members);
    for (unsigned i = 0; i < courses.size(); i++)
    {
        out << courses[i].getId() << ","
            << courses[i].getName() << ","
            << courses[i].getProfId() << ","
            << courses[i].getEnrolled() << ","
            << courses[i].getTimeBlocks();
        set<string> conflicts = courses[i].getConflicts();
        if (conflicts.size() == 0)
            out << ",";
        else
        {
            set<string>::iterator it;
            for (it = conflicts.begin(); it != conflicts.end(); ++it)
                out << "," << (*it);
        }
        out << std::endl;
    }
    out.close();
    return true;
}

bool DataCreator::createVectorFile(string filename, Prof p, int members)
{
    std::ofstream out;
    out.open(filename.c_str());
    if (!out.is_open())
        return false;
    vector<Prof> profs = createVector(p, members);
    for (unsigned i = 0; i < profs.size(); i++)
    {
        out << profs[i].getId() << ","
            << profs[i].getFirstName() << ","
            << profs[i].getLastName() << std::endl;
    }
    out.close();
    return true;
}

bool DataCreator::createVectorFile(string filename, Room r, int members)
{
    std::ofstream out;
    out.open(filename.c_str());
    if (!out.is_open())
        return false;
    vector<Room> rooms = createVector(r, members);
    for (unsigned i = 0; i < rooms.size(); i++)
    {
        out << rooms[i].getId() << ","
            << rooms[i].getCapacity() << std::endl;
    }
    out.close();
    return true;
}

void DataCreator::loadProfs(vector<Course>& courses, const vector<Prof>& profs)
{
    int profIndex;
    for (unsigned i = 0; i < courses.size(); i++)
    {
        profIndex = rand() % profs.size();
        courses[i].setProfId(profs[profIndex].getId());
    }
}

