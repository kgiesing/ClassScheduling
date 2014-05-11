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
    Course c1 = DataCreator::createCourse();
    c1.setProfId(profs[0].getId());
    Course c2 = DataCreator::createCourse();
    c2.setProfId(profs[1].getId());

    // Instantiate new Schedule
    instance = new Schedule(rooms, profs);
    cout << "Successfully created Prof object with data" << endl;
    cout << "Test courses passed as arguments:" << endl;
    cout << "\tc1: " << endl;
    ObjectPrinter::print(c1, "\t   ");
    cout << "\tc2: " << endl;
    ObjectPrinter::print(c2, "\t   ");

    // Test accessors
    cout << "Testing accessors..." << endl;
    cout << "\tgetCourse(rooms[0], MON, START_08_00): " << endl;
    ObjectPrinter::print(instance->getCourse(rooms[0], MON, START_08_00), "\t");
    cout << "\tgetCoursesAt(MON, START_08_00): " << endl;
    VectorPrinter::print(instance->getCoursesAt(MON, START_08_00), "\t");
    cout << "\tgetProf(c1): " << endl;
    ObjectPrinter::print(instance->getProf(c1), "\t");
    cout << "\tgetProf(c2): " << endl;
    ObjectPrinter::print(instance->getProf(c1), "\t");
    cout << "\tgetProf(\"" << profs[0].getId() << "\"): " << endl;
    ObjectPrinter::print(instance->getProf(profs[0].getId()), "\t");
    cout << "\tgetRoomFor(c1): " << endl;
    ObjectPrinter::print(instance->getRoomFor(c1), "\t");
    cout << "\tgetRoomFor(c2): " << endl;
    ObjectPrinter::print(instance->getRoomFor(c2), "\t");
    cout << "\tgetScore(): " << endl;
    cout << "\t" << instance->getScore() << endl;
    cout << "\tgetTimeFor(c1): " << endl;
    ObjectPrinter::print(instance->getTimeFor(c2), "\t");
    cout << "\tgetTimeFor(c2): " << endl;
    ObjectPrinter::print(instance->getTimeFor(c2), "\t");
    cout << "\tgetWeekdaysFor(c1): " << endl;
    VectorPrinter::print(instance->getWeekdaysFor(c1), "\t");
    cout << "\tgetWeekdaysFor(c2): " << endl;
    VectorPrinter::print(instance->getWeekdaysFor(c2), "\t");

    // Test mutators
    cout << "Testing mutators..." << endl;
    cout << "\tsetCourse(c1, rooms[0], MON, START_08_00, 2): "
         << instance->setCourse(c1, rooms[0], MON, START_08_00, 2) << endl;
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
    cout << "\tgetCoursesAt(MON, START_08_00): " << endl;
    VectorPrinter::print(instance->getCoursesAt(MON, START_08_00), "\t");
    cout << "\tgetProf(c1): " << endl;
    ObjectPrinter::print(instance->getProf(c1), "\t");
    cout << "\tgetProf(c2): " << endl;
    ObjectPrinter::print(instance->getProf(c1), "\t");
    cout << "\tgetProf(\"" << profs[0].getId() << "\"): " << endl;
    ObjectPrinter::print(instance->getProf(profs[0].getId()), "\t");
    cout << "\tgetRoomFor(c1): " << endl;
    ObjectPrinter::print(instance->getRoomFor(c1), "\t");
    cout << "\tgetRoomFor(c2): " << endl;
    ObjectPrinter::print(instance->getRoomFor(c2), "\t");
    cout << "\tgetScore(): " << endl;
    cout << "\t" << instance->getScore() << endl;
    cout << "\tgetTimeFor(c1): " << endl;
    ObjectPrinter::print(instance->getTimeFor(c2), "\t");
    cout << "\tgetTimeFor(c2): " << endl;
    ObjectPrinter::print(instance->getTimeFor(c2), "\t");
    cout << "\tgetWeekdaysFor(c1): " << endl;
    VectorPrinter::print(instance->getWeekdaysFor(c1), "\t");
    cout << "\tgetWeekdaysFor(c2): " << endl;
    VectorPrinter::print(instance->getWeekdaysFor(c2), "\t");

    delete instance;
}
