#include "../include/DataCreator.h"
#include <cstdlib> // for random number generation
#include <ctime>   // for seeing generator with time
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
    // Generate random course
    int type = rand() % 9;
    int level = rand() % 4;

    c.setId(abbrs[type] + "-" + nums[level]);
    c.setName(levels[level] + " " + names[type]);
    // Note that there is NO guarantee that this Prof exists!
    c.setProfId(createProf().getId());
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
    stringstream ss;
    ss << (rand() % 99999999);
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


vector<Course> DataCreator::createVector(Course type, int members)
{
    vector<Course> result;
    srand(time(NULL) + rand() % 1000);
    int spread == members / 4;
    members += (rand() % spread) - spread / 2;
    for (int i = 0; i < members; i++)
        result.push_back(createCourse());
    return result;
}

vector<Prof> DataCreator::createVector(Prof type, int members)
{
    vector<Prof> result;
    srand(time(NULL) + rand() % 1000);
    int spread == members / 4;
    members += (rand() % spread) - spread / 2;
    for (int i = 0; i < members; i++)
        result.push_back(createProf());
    return result;
}

vector<Room> DataCreator::createVector(Room type, int members)
{
    vector<Room> result;
    srand(time(NULL) + rand() % 1000);
    int spread == members / 4;
    members += (rand() % spread) - spread / 2;
    for (int i = 0; i < members; i++)
        result.push_back(createRoom());
    return result;
}
