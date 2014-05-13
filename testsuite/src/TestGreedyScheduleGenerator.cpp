#include "../include/TestGreedyScheduleGenerator.h"
#include "../include/DataCreator.h"
#include "../include/ObjectPrinter.h"
#include "../../include/GreedyScheduleGenerator.h"
#include <ctime>
#include <cstdlib>

void TestGreedyScheduleGenerator::testPass(void)
{
    // Test the greedy schedule generator.
    GreedyScheduleGenerator* instance;

    vector<Course> courses = DataCreator::createVector(DataCreator::createCourse(), 50);
    vector<Prof> profs = DataCreator::createVector(DataCreator::createProf());
    vector<Room> rooms = DataCreator::createVector(DataCreator::createRoom());
    DataCreator::loadProfs(courses, profs);

    // Instantiate new Schedule
    instance = new GreedyScheduleGenerator(rooms, profs, courses, time(NULL));
    cout << "Successfully created GreedyScheduleGenerator object with data" << endl;

    // Test accessors
    cout << "Testing accessors:" << endl;
    cout << "\tgetTimeout: " << instance->getTimeout() << endl;
    cout << "\tgetSchedule: " << endl;
    ObjectPrinter::print(*(instance->getSchedule()), "\t");

    delete instance;
}

void TestGreedyScheduleGenerator::testFail(void)
{
    // Fail test the greedy schedule generator.
    GreedyScheduleGenerator* instance;

    vector<Course> courses = DataCreator::createVector(DataCreator::createCourse(), 50);
    vector<Prof> profs = DataCreator::createVector(DataCreator::createProf());
    vector<Room> rooms = DataCreator::createVector(DataCreator::createRoom());
    // Don't match professors to courses

    // Test invalid professor ID's
    cout << "Testing with invalid professor ID's..." << endl;
    instance = new GreedyScheduleGenerator(rooms, profs, courses, time(NULL));
    cout << "Successfully created GreedyScheduleGenerator object with invalid data" << endl;
    cout << "\tgetSchedule: " << endl;
    ObjectPrinter::print(*(instance->getSchedule()), "\t");
    delete instance;

    // Test invalid enrollment
    cout << "Testing with invalid enrollment..." << endl;
    DataCreator::loadProfs(courses, profs);
    srand(time(NULL));
    courses[rand() % courses.size()].setEnrolled(200);
    courses[rand() % courses.size()].setEnrolled(300);
    courses[rand() % courses.size()].setEnrolled(400);
    instance = new GreedyScheduleGenerator(rooms, profs, courses, time(NULL));
    cout << "Successfully created GreedyScheduleGenerator object with invalid data" << endl;
    cout << "\tgetSchedule: " << endl;
    ObjectPrinter::print(*(instance->getSchedule()), "\t");
    delete instance;

    // Test invalid number of courses
    cout << "Testing with invalid number of courses..." << endl;
    courses = DataCreator::createVector(DataCreator::createCourse(), 200);
    profs   = DataCreator::createVector(DataCreator::createProf(), 100);
    rooms   = DataCreator::createVector(DataCreator::createRoom(), 10);
    DataCreator::loadProfs(courses, profs);
    instance = new GreedyScheduleGenerator(rooms, profs, courses, time(NULL));
    cout << "Successfully created GreedyScheduleGenerator object with invalid data" << endl;
    cout << "\tgetSchedule: " << endl;
    ObjectPrinter::print(*(instance->getSchedule()), "\t");
    delete instance;
}

