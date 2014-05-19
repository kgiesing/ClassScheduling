#include "../include/DataCreator.h"
#include <cstdlib> // for random number generation
#include <ctime>   // for seeing generator with time
#include <fstream> // for creating files
#include <sstream> // for converting int to string

Course DataCreator::createCourse(void)

{
    Course c;
    Prof p;
    std::stringstream ss;
    string names[] = {"Accounting/Finance", "Africana Studies",
            "American Studies", "Anthropology", "Arabic", "Art",
            "Asian Studies", "Business Communications", "Biochemistry",
            "Biology", "Community Development", "Chemistry", "Chinese",
            "Classics", "Communication Studies", "Criminal Justice",
            "Critical Reading & Writing", "Computer Science", "Dance",
            "Early Childhood Education", "Economics", "Education",
            "Exercise and Health Science", "Engineering", "English",
            "Environmental Studies", "French", "German", "Gerontology",
            "Global Affairs", "Greek", "History", "Humanities",
            "Human Services", "International Relations",
            "Information Technology", "Italian", "Japanese",
            "Latin American Studies", "Latin", "Legal Education Services",
            "Linguistics", "Mathematics", "Modern Languages", "Management",
            "Marketing", "Management Information Systems", "Music",
            "Native American Studies", "Nursing", "Philosophy", "Physics",
            "Political Science", "Portuguese", "Psychology",
            "Study of Religion", "Russian", "Sociology", "Spanish",
            "Theatre Arts", "Vietnamese", "Women's Studies"};
    string abbrs[] = {"AF", "AFRSTY", "AMST", "ANTH", "ARABIC", "ART", "ASIAN",
            "BC", "BIOCHM", "BIOL", "CDVCTR", "CHEM", "CHINSE", "CLSICS",
            "COMSTU", "CRMJUS", "CRW", "CS", "DANCE", "ECHD", "ECON", "EDCG",
            "EHS", "ENGIN", "ENGL", "ENVSTY", "FRENCH", "GERMAN", "GERON",
            "GLBAFF", "GREEK", "HIST", "HUMAN", "HUMCTR", "IR", "IT", "ITAL",
            "JAPAN", "LATAM", "LATIN", "LAWCTR", "LING", "MATH", "MDNLNG",
            "MGT", "MKT", "MSIS", "MUSIC", "NAIS", "NURSNG", "PHIL", "PHYSIC",
            "POLSCI", "PORT", "PSYCH", "RELSTY", "RUSS", "SOCIOL", "SPAN",
            "THRART", "VIET", "WOST"};
    string levels[] = {"Introductory", "Intermediate", "Advanced",
                       "Topics in", "Graduate"};
    string nums[] = {"110", "220", "340", "440", "650"};
    // Generate random course
    int type = rand() % 62;
    int level = rand() % 5;

    ss << abbrs[type] << "-" + nums[level] << "-" << (rand() % 2 + 1);
    c.setId(ss.str());
    c.setName(levels[level] + " " + names[type]);
    // Note that there is NO guarantee that this Prof exists!
    p = createProf();
    c.setProfId(p.getId());
    c.setEnrolled(rand() % 40);

    // Create some random conflicts
    set<string> conflicts;
    int numConflicts = rand() % 4;
    int newType = type;
    for(int i = 0; i < numConflicts; i++)
    {
        // Conflict is different course at same level
        // Note that there is NO guarantee that this Course exists!
        while(newType == type)
            newType = (type + rand()) % 9;
        ss.str("");
        ss << abbrs[newType] << "-" + nums[level] << "-" << (rand() % 2 + 1);
        conflicts.insert(ss.str());
    }
    c.setConflicts(conflicts);

    return c;
}

Prof DataCreator::createProf(void)
{
    string fnames[] = {"Alfred", "Amy", "Ava", "Bob", "Christopher", "David",
            "Emily", "Isabella", "Jacob", "James", "Jason", "Jennifer", "John",
            "Kimberly", "Liam", "Lin", "Lisa", "Martin", "Mason", "Matthew",
            "Mary", "Michael", "Michelle", "Noah", "Olivia", "Patricia",
            "Peter", "Ronald", "Sophia" ,"William"};
    string lnames[] = {"Allen" ,"Anderson", "Brown", "Campbell", "Chen",
            "Clark", "Davis", "Garcia", "Gonzalez", "Hall", "Harris",
            "Hernandez", "Jackson", "Johnson", "Jones", "Lee", "Lewis",
            "Lopez", "Martin", "Martinez", "Miller", "Moore", "Nguyen",
            "Patel", "Perez", "Robinson", "Rodriguez", "Sanchez", "Singh",
            "Smith", "Taylor", "Thomas", "Thompson", "Walker", "White",
            "Williams", "Wilson", "Wong", "Wright", "Young"};
    Prof p;
    // ID is simply an 8-digit number
    std::stringstream ss;
    ss << (rand() % 9999999) + 10000000 * (rand() % 9 + 1);
    p.setId(ss.str());
    // Randomly set first and last names
    p.setFirstName(fnames[rand() % 30]);
    p.setLastName(lnames[rand() % 40]);
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
    string id = bldgs[rand() % 3] + "-" + floors[floor] + "-"
            + floors[rand() % 4] + rooms[rand() % 10];
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
    // Create valid sample data for initialization
    vector<Prof> profs = DataCreator::createVector(DataCreator::createProf(), 100);
    vector<Room> rooms = DataCreator::createVector(DataCreator::createRoom(), 20);
    vector<Course> courses = DataCreator::createVector(DataCreator::createCourse(), 300);
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
            if (rooms[idxRooms].getCapacity() < courses[c].getEnrolled())
            {
                int orig = idxRooms++;
                while(rooms[idxRooms].getCapacity() < courses[c].getEnrolled()
                        && orig != idxRooms)
                    idxRooms = (idxRooms + 1) % rooms.size();
                if(orig == idxRooms)  // All rooms too small; increase capacity
                    rooms[idxRooms].setCapacity(courses[c].getEnrolled() + 1);

            }
            else
            {
                Weekdays wd = static_cast<Weekdays>(day);
                TimeBlock tb = static_cast<TimeBlock>(time);
                ok = s.setCourse(courses[c], rooms[idxRooms], wd, tb);
                time++;
                if (time >= TIMEBLOCK_SIZE)
                {
                    time = 0;
                    day++;
                }
                if (day >= WEEKDAYS_SIZE)
                {
                    time = 0;
                    day = 0;
                    idxRooms++;
                }
            }
        }
    }
    return s;
}

vector<Course> DataCreator::createVector(Course type, int members)
{
    vector<Course> result;
    map<string, Course> sorted;
    map<string, Course>::iterator it;
    Course member;

    srand(time(NULL) + rand() % 1000);
    int spread = members / 4;
    members += (rand() % spread) - spread / 2;
    members = (members < 1 ? 1 : members);
    for (int i = 0; i < members; i++)
    {
        do
            member = createCourse();
        while (sorted.find(member.getId()) != sorted.end());
        sorted[member.getId()] = member;
    }
    for (it = sorted.begin(); it != sorted.end(); it++)
        result.push_back(it->second);
    return result;
}

vector<Prof> DataCreator::createVector(Prof type, int members)
{
    vector<Prof> result;
    map<string, Prof> sorted;
    map<string, Prof>::iterator it;
    Prof member;

    srand(time(NULL) + rand() % 1000);
    int spread = members / 4;
    members += (rand() % spread) - spread / 2;
    members = (members < 1 ? 1 : members);
    for (int i = 0; i < members; i++)
    {
        do
            member = createProf();
        while (sorted.find(member.getId()) != sorted.end());
        sorted[member.getId()] = member;
    }
    for (it = sorted.begin(); it != sorted.end(); it++)
        result.push_back(it->second);
    return result;
}

vector<Room> DataCreator::createVector(Room type, int members)
{
    vector<Room> result;
    map<string, Room> sorted;
    map<string, Room>::iterator it;
    Room member;

    srand(time(NULL) + rand() % 1000);
    int spread = members / 4;
    members += (rand() % spread) - spread / 2;
    members = (members < 1 ? 1 : members);
    for (int i = 0; i < members; i++)
    {
        do
            member = createRoom();
        while (sorted.find(member.getId()) != sorted.end());
        sorted[member.getId()] = member;
    }
    for (it = sorted.begin(); it != sorted.end(); it++)
        result.push_back(it->second);
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

