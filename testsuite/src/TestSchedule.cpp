#include "../include/TestSchedule.h"
#include "../include/DataCreator.h"
#include "../include/MapPrinter.h"
#include "../include/ObjectPrinter.h"
#include "../include/VectorPrinter.h"
#include "../../include/Schedule.h"

void TestSchedule::testPass(void)
{
    Schedule* instance;
    Schedule* duplicate;
    // Create valid sample data for initialization
    vector<Prof> profs = DataCreator::createVector(DataCreator::createProf(), 100);
    vector<Room> rooms = DataCreator::createVector(DataCreator::createRoom(), 20);
    vector<Course> courses = DataCreator::createVector(DataCreator::createCourse(), 300);
    DataCreator::loadProfs(courses, profs);

    // Instantiate new Schedule
    instance = new Schedule(rooms, profs, courses);
    cout << "Successfully created Schedule object with data:" << endl;
    VectorPrinter::print(profs);
    VectorPrinter::print(courses);
    VectorPrinter::print(rooms);

    // Choose a course as a test parameter
    Course c  = courses[10];
    Course c2 = courses[5];
    cout << "Course objects passed as parameter:" << endl
         << "\tc: ";
    ObjectPrinter::print(c, "\t    ");
    cout << "\tc2: ";
    ObjectPrinter::print(c2, "\t    ");

    // Test accessors
    cout << "Testing accessors:" << endl;
    cout << "\tgetCourse(rooms[0], MON, START_08_00): " << endl << "\t";
    ObjectPrinter::print(instance->getCourse(rooms[0], MON, START_08_00), "\t");
    cout << "\tgetCourse(rooms[0], TUES, START_14_00): " << endl << "\t";
    ObjectPrinter::print(instance->getCourse(rooms[0], TUES, START_14_00), "\t");
    cout << "\tgetCoursesAt(MON, START_08_00): " << endl << "\t";
    VectorPrinter::print(instance->getCoursesAt(MON, START_08_00), "\t");
    cout << "\tgetCoursesAt(TUES, START_14_00): " << endl << "\t";
    VectorPrinter::print(instance->getCoursesAt(TUES, START_14_00), "\t");
    cout << "\tgetProf(c): ";
    ObjectPrinter::print(instance->getProf(c));
    cout << "\tgetProf(c2): ";
    ObjectPrinter::print(instance->getProf(c2));
    cout << "\tgetProf(\"" << profs[0].getId() << "\"): ";
    ObjectPrinter::print(instance->getProf(profs[0].getId()));
    cout << "\tgetProfs(): ";
    MapPrinter::print(instance->getProfs(), "\t");
    cout << "\tgetRoomFor(c): ";
    ObjectPrinter::print(instance->getRoomFor(c));
    cout << "\tgetRoomFor(c2): ";
    ObjectPrinter::print(instance->getRoomFor(c));
    cout << "\n\tgetScore(): " << instance->getScore();
    cout << "\n\tgetTimeFor(c): ";
    ObjectPrinter::print(instance->getTimeFor(c));
    cout << "\n\tgetTimeFor(c2): ";
    ObjectPrinter::print(instance->getTimeFor(c2));
    cout << "\n\tgetWeekdaysFor(c): " << endl << "\t";
    VectorPrinter::print(instance->getWeekdaysFor(c), "\t");
    cout << "\tgetWeekdaysFor(c2): " << endl << "\t";
    VectorPrinter::print(instance->getWeekdaysFor(c2), "\t");

    // Test mutators
    cout << "Testing mutators..." << endl;
    cout << "\tsetCourse(c, rooms[0], MON, START_08_00, 2): "
         << instance->setCourse(c, rooms[0], MON, START_08_00) << endl;
    cout << "\tsetCourse(c2, rooms[1], TUES, START_14_00, 2): "
         << instance->setCourse(c2, rooms[1], TUES, START_14_00) << endl;
    cout << "\tsetScore(100.0)..." << endl;
    instance->setScore(100.0);
    cout << "\tswapCourses(rooms[0], MON, START_08_00, rooms[1], TUES,"
         << endl << "\t            START_14_00)..." << endl;
    instance->swapCourses(rooms[0], MON, START_08_00, rooms[1], TUES,
                          START_14_00);

    // Output values after mutating
    cout << "Object after mutating:" << endl;
    cout << "\tgetCourse(rooms[0], MON, START_08_00): " << endl << "\t";
    ObjectPrinter::print(instance->getCourse(rooms[0], MON, START_08_00), "\t");
    cout << "\tgetCourse(rooms[0], TUES, START_14_00): " << endl << "\t";
    ObjectPrinter::print(instance->getCourse(rooms[0], TUES, START_14_00), "\t");
    cout << "\tgetCoursesAt(MON, START_08_00): " << endl << "\t";
    VectorPrinter::print(instance->getCoursesAt(MON, START_08_00), "\t");
    cout << "\tgetCoursesAt(TUES, START_14_00): " << endl << "\t";
    VectorPrinter::print(instance->getCoursesAt(TUES, START_14_00), "\t");
    cout << "\tgetProf(c): ";
    ObjectPrinter::print(instance->getProf(c));
    cout << "\tgetProf(c2): ";
    ObjectPrinter::print(instance->getProf(c2));
    cout << "\tgetProf(\"" << profs[0].getId() << "\"): ";
    ObjectPrinter::print(instance->getProf(profs[0].getId()));
    cout << "\tgetRoomFor(c): ";
    ObjectPrinter::print(instance->getRoomFor(c));
    cout << "\tgetRoomFor(c2): ";
    ObjectPrinter::print(instance->getRoomFor(c));
    cout << "\n\tgetScore(): " << instance->getScore();
    cout << "\n\tgetTimeFor(c): ";
    ObjectPrinter::print(instance->getTimeFor(c));
    cout << "\n\tgetTimeFor(c2): ";
    ObjectPrinter::print(instance->getTimeFor(c2));
    cout << "\n\tgetWeekdaysFor(c): " << endl << "\t";
    VectorPrinter::print(instance->getWeekdaysFor(c), "\t");
    cout << "\tgetWeekdaysFor(c2): " << endl << "\t";
    VectorPrinter::print(instance->getWeekdaysFor(c2), "\t");

    // Go through the Courses, and schedule them.
    cout << "Scheduling courses:" << endl;
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
                cout << "\tsetCourse(" << courses[c].getId()
                     << ", " << rooms[idxRooms].getId()
                     << ", " << wd << ", " << tb
                     << ", " << courses[c].getTimeBlocks() << "): ";
                ok = instance->setCourse(courses[c], rooms[idxRooms], wd, tb);
                cout << ok << endl;
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
    cout << "Successfully scheduled courses." << endl;

    // Test copy constructor
    cout << "Testing copy constructor..." << endl;
    duplicate = new Schedule(*instance);
    cout << "\tSuccessfully copied Schedule object" << endl
         << "\tDeleting original Schedule..." << endl;
    Schedule* temp = duplicate;
    duplicate = instance;
    instance = temp;
    delete duplicate;
    cout << "Original Schedule deleted. Deleting copy..." << endl;

    // Done
    delete instance;
    cout << "Done." << endl;
}

void TestSchedule::testFail(void)
{
    Schedule* instance;
    // Create valid sample data for initialization
    vector<Prof> profs = DataCreator::createVector(DataCreator::createProf(), 10);
    vector<Room> rooms = DataCreator::createVector(DataCreator::createRoom(), 5);
    vector<Course> courses = DataCreator::createVector(DataCreator::createCourse(), 100);

    // Instantiate new Schedule
    instance = new Schedule(rooms, profs, courses);
    cout << "Successfully created Schedule object with data" << endl;

    // Choose test parameters
    Course c  = courses[5];
    c.setProfId("INVALID");
    cout << "Course object passed as parameter:" << endl
         << "\tc: ";
    ObjectPrinter::print(c, "\t    ");
    Room r = rooms[1];
    r.setId("INVALID");
    cout << "Room object passed as parameter:" << endl
         << "\tr: ";
    ObjectPrinter::print(r, "\t    ");

    // Test accessors
    cout << "Testing accessors with invalid values:" << endl;
    cout << "\tgetCourse(" << rooms[0].getId() << ", WEEKDAYS_SIZE, START_08_00): " << endl << "\t";
    ObjectPrinter::print(instance->getCourse(rooms[0], WEEKDAYS_SIZE, START_08_00), "\t");
    cout << "\tgetCourse(" << rooms[0].getId() << ", TUES, TIMEBLOCK_SIZE): " << endl << "\t";
    ObjectPrinter::print(instance->getCourse(rooms[0], TUES, TIMEBLOCK_SIZE), "\t");
    cout << "\tgetCourse(" << r.getId() << ", MON, START_08_00): " << endl << "\t";
    ObjectPrinter::print(instance->getCourse(r.getId(), MON, START_08_00), "\t");
    cout << "\tgetCoursesAt(MON, TIMEBLOCK_SIZE): " << endl << "\t";
    VectorPrinter::print(instance->getCoursesAt(MON, TIMEBLOCK_SIZE), "\t");
    cout << "\tgetCoursesAt(WEEKDAYS_SIZE, START_14_00): " << endl << "\t";
    VectorPrinter::print(instance->getCoursesAt(WEEKDAYS_SIZE, START_14_00), "\t");
    cout << "\tgetProf(c): ";
    ObjectPrinter::print(instance->getProf(c));
    cout << "\tgetProf(\"INVALID\"): ";
    ObjectPrinter::print(instance->getProf("INVALID"));
    cout << "\tgetRoomFor(c): ";
    ObjectPrinter::print(instance->getRoomFor(c));
    cout << "\n\tgetTimeFor(c): ";
    ObjectPrinter::print(instance->getTimeFor(c));
    cout << "\tgetWeekdaysFor(c): " << endl << "\t";
    VectorPrinter::print(instance->getWeekdaysFor(c), "\t");

    // Test mutators
    cout << "Testing mutators..." << endl;
    cout << "\tsetCourse(c, rooms[0], WEEKDAYS_SIZE, START_08_00, 2): "
         << instance->setCourse(c, rooms[0], WEEKDAYS_SIZE, START_08_00)
         << endl;
    cout << "\tsetCourse(c, rooms[1], TUES, TIMEBLOCK_SIZE, 2): "
         << instance->setCourse(c, rooms[1], TUES, TIMEBLOCK_SIZE) << endl;
    cout << "\tswapCourses(rooms[0], WEEKDAYS_SIZE, START_08_00, rooms[1], TUES,"
         << endl << "\t            TIMEBLOCK_SIZE)..." << endl;
    instance->swapCourses(rooms[0], WEEKDAYS_SIZE, START_08_00, rooms[1], TUES,
                          TIMEBLOCK_SIZE);

    // Output values after mutating
    cout << "Object after mutating:" << endl;
    cout << "\tgetCourse(" << rooms[0].getId() << ", WEEKDAYS_SIZE, START_08_00): " << endl << "\t";
    ObjectPrinter::print(instance->getCourse(rooms[0], WEEKDAYS_SIZE, START_08_00), "\t");
    cout << "\tgetCourse(" << rooms[0].getId() << ", TUES, TIMEBLOCK_SIZE): " << endl << "\t";
    ObjectPrinter::print(instance->getCourse(rooms[0], TUES, TIMEBLOCK_SIZE), "\t");
    cout << "\tgetCourse(" << r.getId() << ", MON, START_08_00): " << endl << "\t";
    ObjectPrinter::print(instance->getCourse(r.getId(), MON, START_08_00), "\t");
    cout << "\tgetCoursesAt(MON, TIMEBLOCK_SIZE): " << endl << "\t";
    VectorPrinter::print(instance->getCoursesAt(MON, TIMEBLOCK_SIZE), "\t");
    cout << "\tgetCoursesAt(WEEKDAYS_SIZE, START_14_00): " << endl << "\t";
    VectorPrinter::print(instance->getCoursesAt(WEEKDAYS_SIZE, START_14_00), "\t");
    cout << "\tgetProf(c): ";
    ObjectPrinter::print(instance->getProf(c));
    cout << "\tgetProf(\"INVALID\"): ";
    ObjectPrinter::print(instance->getProf("INVALID"));
    cout << "\tgetRoomFor(c): ";
    ObjectPrinter::print(instance->getRoomFor(c));
    cout << "\n\tgetTimeFor(c): ";
    ObjectPrinter::print(instance->getTimeFor(c));
    cout << "\tgetWeekdaysFor(c): " << endl << "\t";
    VectorPrinter::print(instance->getWeekdaysFor(c), "\t");

    // Done
    delete instance;
}

