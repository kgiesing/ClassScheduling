#include "../include/TestScheduleCalculator.h"
#include "../include/DataCreator.h"
#include "../include/ObjectPrinter.h"
#include "../../include/ScheduleCalculator.h"
#include "../../include/LinearScoreCalculator.h"
#include "../../include/WeightedScoreCalculator.h"


void TestScheduleCalculator::testPass(void)
{
    // Create very simple data for testing
    cout << "Creating test data..." << endl;
    vector<Room> rooms = DataCreator::createVector(DataCreator::createRoom());
    vector<Prof> profs = DataCreator::createVector(DataCreator::createProf());
    vector<Course> courses = DataCreator::createVector(DataCreator::createCourse());
    rooms.resize(3);
    profs.resize(1);
    courses.resize(3);
    for (unsigned i = 0; i < courses.size(); i++)
        courses[i].setProfId(profs[0].getId());
    Schedule s(rooms, profs, courses);
    s.setCourse(courses[0], rooms[0], MON, START_08_00);
    s.setCourse(courses[1], rooms[1], MON, START_20_00);
    s.setCourse(courses[2], rooms[2], TUES, START_12_30);
    LinearScoreCalculator linear;
    WeightedScoreCalculator weighted;

    // Output sample data
    cout << "Test data: "
         << "\n\tlinear: LinearScoreCalculator"
         << "\n\tweighted: WeightedScoreCalculator\n\r";
    ObjectPrinter::print(s, "\t");

    // Test static members
    cout << "Testing static members..." << endl;
    cout << "\tcalculateScore(s, linear): "
         << ScheduleCalculator::calculateScore(&s, linear) << endl;
    cout << "\tcalculateScore(s, weighted): "
         << ScheduleCalculator::calculateScore(&s, weighted) << endl;
    cout << endl;
}

void TestScheduleCalculator::testStress(unsigned seconds)
{

    // Declare variables
    time_t future;
    unsigned long iterations;

    // Create object
    cout << "Creating objects and test data..." << endl;
    LinearScoreCalculator linear;
    WeightedScoreCalculator weighted;
    Schedule s = DataCreator::createSchedule();

    // Stress test WeightedScoreCalculator
    cout << "Stress testing calculateScore(s, weighted)..." << endl;
    iterations = 0;
    future = time(NULL) + seconds;
    while (time(NULL) < future)
    {
        ScheduleCalculator::calculateScore(&s, weighted);
        iterations++;
    }
    cout << "\t" << iterations << " iterations in "
         << seconds << " seconds" << endl;

     // Stress test LinearScoreCalculator
    cout << "Stress testing calculateScore(s, linear)..." << endl;
    iterations = 0;
    future = time(NULL) + seconds;
    while (time(NULL) < future)
    {
        ScheduleCalculator::calculateScore(&s, linear);
        iterations++;
    }
    cout << "\t" << iterations << " iterations in "
         << seconds << " seconds" << endl;
}

