#include "../include/TestSchedule.h"
#include "../include/DataCreator.h"
#include "../include/ObjectPrinter.h"
#include "../include/VectorPrinter.h"
#include "../../include/Schedule.h"

void TestSchedule::testPass(void)
{
    Schedule* instance;
    // Create valid sample data for initialization
    vector<Prof> profs = DataCreator::createVector(DataCreator::createProf());
    vector<Room> rooms = DataCreator::createVector(DataCreator::createRoom());
    vector<Course> courses = DataCreator::createVector(DataCreator::createCourse());
    DataCreator::loadProfs(courses, profs);

    // Instantiate new Schedule
    instance = new Schedule(rooms, profs, courses);
    cout << "Successfully created Prof object with data" << endl;

    // Choose a course as a test parameter
    Course c  = courses[10];
    Course c2 = courses[5];
    cout << "Course objects passed as parameter:" << endl
         << "\tc: ";
    ObjectPrinter::print(c, "\t    ");
    cout << "\tc2: ";
    ObjectPrinter::print(c2, "\t    ");

    // Test accessors
    cout << "Object after mutating:" << endl;
    cout << "\tgetCourse(rooms[0], MON, START_08_00): " << endl;
    ObjectPrinter::print(instance->getCourse(rooms[0], MON, START_08_00), "\t");
    cout << "\tgetCourse(rooms[0], TUES, START_14_00): " << endl;
    ObjectPrinter::print(instance->getCourse(rooms[0], TUES, START_14_00), "\t");
    cout << "\tgetCoursesAt(MON, START_08_00): " << endl;
    VectorPrinter::print(instance->getCoursesAt(MON, START_08_00), "\t");
    cout << "\tgetCoursesAt(TUES, START_14_00): " << endl;
    VectorPrinter::print(instance->getCoursesAt(TUES, START_14_00), "\t");
    cout << "\tgetProf(c): " << endl;
    ObjectPrinter::print(instance->getProf(c), "\t");
    cout << "\tgetProf(c2): " << endl;
    ObjectPrinter::print(instance->getProf(c2), "\t");
    cout << "\tgetProf(\"" << profs[0].getId() << "\"): " << endl;
    ObjectPrinter::print(instance->getProf(profs[0].getId()), "\t");
    cout << "\tgetRoomFor(c): " << endl;
    ObjectPrinter::print(instance->getRoomFor(c), "\t");
    cout << "\tgetRoomFor(c2): " << endl;
    ObjectPrinter::print(instance->getRoomFor(c), "\t");
    cout << "\tgetScore(): " << endl;
    cout << "\t" << instance->getScore() << endl;
    cout << "\tgetTimeFor(c): " << endl;
    ObjectPrinter::print(instance->getTimeFor(c), "\t");
    cout << "\tgetTimeFor(c2): " << endl;
    ObjectPrinter::print(instance->getTimeFor(c2), "\t");
    cout << "\tgetWeekdaysFor(c): " << endl;
    VectorPrinter::print(instance->getWeekdaysFor(c), "\t");
    cout << "\tgetWeekdaysFor(c2): " << endl;
    VectorPrinter::print(instance->getWeekdaysFor(c2), "\t");

    // Test mutators
    cout << "Testing mutators..." << endl;
    cout << "\tsetCourse(c, rooms[0], MON, START_08_00, 2): "
         << instance->setCourse(c, rooms[0], MON, START_08_00, 2) << endl;
    cout << "\tsetCourse(c2, rooms[1], TUES, START_14_00, 2): "
         << instance->setCourse(c2, rooms[1], TUES, START_14_00, 2) << endl;
    cout << "\tsetScore(100.0)..." << endl;
    instance->setScore(100.0);
    cout << "\tswapCourses(rooms[0], MON, START_08_00, rooms[1], TUES,"
         << endl << "\t            START_14_00)..." << endl;
    instance->swapCourses(rooms[0], MON, START_08_00, rooms[1], TUES,
                          START_14_00);

    // Output values after mutating
    cout << "Object after mutating:" << endl;
    cout << "\tgetCourse(rooms[0], MON, START_08_00): " << endl;
    ObjectPrinter::print(instance->getCourse(rooms[0], MON, START_08_00), "\t");
    cout << "\tgetCourse(rooms[0], TUES, START_14_00): " << endl;
    ObjectPrinter::print(instance->getCourse(rooms[0], TUES, START_14_00), "\t");
    cout << "\tgetCoursesAt(MON, START_08_00): " << endl;
    VectorPrinter::print(instance->getCoursesAt(MON, START_08_00), "\t");
    cout << "\tgetCoursesAt(TUES, START_14_00): " << endl;
    VectorPrinter::print(instance->getCoursesAt(TUES, START_14_00), "\t");
    cout << "\tgetProf(c): " << endl;
    ObjectPrinter::print(instance->getProf(c), "\t");
    cout << "\tgetProf(c2): " << endl;
    ObjectPrinter::print(instance->getProf(c2), "\t");
    cout << "\tgetProf(\"" << profs[0].getId() << "\"): " << endl;
    ObjectPrinter::print(instance->getProf(profs[0].getId()), "\t");
    cout << "\tgetRoomFor(c): " << endl;
    ObjectPrinter::print(instance->getRoomFor(c), "\t");
    cout << "\tgetRoomFor(c2): " << endl;
    ObjectPrinter::print(instance->getRoomFor(c), "\t");
    cout << "\tgetScore(): " << endl;
    cout << "\t" << instance->getScore() << endl;
    cout << "\tgetTimeFor(c): " << endl;
    ObjectPrinter::print(instance->getTimeFor(c), "\t");
    cout << "\tgetTimeFor(c2): " << endl;
    ObjectPrinter::print(instance->getTimeFor(c2), "\t");
    cout << "\tgetWeekdaysFor(c): " << endl;
    VectorPrinter::print(instance->getWeekdaysFor(c), "\t");
    cout << "\tgetWeekdaysFor(c2): " << endl;
    VectorPrinter::print(instance->getWeekdaysFor(c2), "\t");

    delete instance;
}
