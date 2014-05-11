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
    cout << "\tgetRoomFor(c): ";
    ObjectPrinter::print(instance->getRoomFor(c));
    cout << "\tgetRoomFor(c2): ";
    ObjectPrinter::print(instance->getRoomFor(c));
    cout << "\tgetScore(): " << instance->getScore();
    cout << "\n\tgetTimeFor(c): ";
    ObjectPrinter::print(instance->getTimeFor(c));
    cout << "\n\ntgetTimeFor(c2): ";
    ObjectPrinter::print(instance->getTimeFor(c2));
    cout << "\tgetWeekdaysFor(c): " << endl << "\t";
    VectorPrinter::print(instance->getWeekdaysFor(c), "\t");
    cout << "\tgetWeekdaysFor(c2): " << endl << "\t";
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
    cout << "\tgetScore(): " << instance->getScore();
    cout << "\n\tgetTimeFor(c): ";
    ObjectPrinter::print(instance->getTimeFor(c));
    cout << "\n\tgetTimeFor(c2): ";
    ObjectPrinter::print(instance->getTimeFor(c2));
    cout << "\n\tgetWeekdaysFor(c): " << endl << "\t";
    VectorPrinter::print(instance->getWeekdaysFor(c), "\t");
    cout << "\tgetWeekdaysFor(c2): " << endl << "\t";
    VectorPrinter::print(instance->getWeekdaysFor(c2), "\t");

    delete instance;
}
