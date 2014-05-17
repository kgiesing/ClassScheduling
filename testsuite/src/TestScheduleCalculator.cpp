#include "../include/TestScheduleCalculator.h"
#include "../include/DataCreator.h"
#include "../include/ObjectPrinter.h"
#include "../../include/ScheduleCalculator.h"
#include "../../include/LinearScoreCalculator.h"
#include "../../include/WeightedScoreCalculator.h"


void TestScheduleCalculator::testPass(void)
{
    // Create valid sample data for testing
    Schedule s = DataCreator::createSchedule();
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
    map<string, Prof> profs = s.getProfs();

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
    cout << "\tResulting score was: " << s.getScore() << endl;

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
    cout << "\tResulting score was: " << s.getScore() << endl;

    // Stress test Dzmitry's version with WeightedScoreCalculator
    cout << "Stress testing calculateScore(s, weighted, profs)..." << endl;
    iterations = 0;
    future = time(NULL) + seconds;
    while (time(NULL) < future)
    {
        ScheduleCalculator::calculateScore(&s, weighted, profs);
        iterations++;
    }
    cout << "\t" << iterations << " iterations in "
         << seconds << " seconds" << endl;
    cout << "\tResulting score was: " << s.getScore() << endl;

     // Stress test Dzmitry's version with LinearScoreCalculator
    cout << "Stress testing calculateScore(s, linear, profs)..." << endl;
    iterations = 0;
    future = time(NULL) + seconds;
    while (time(NULL) < future)
    {
        ScheduleCalculator::calculateScore(&s, linear, profs);
        iterations++;
    }
    cout << "\t" << iterations << " iterations in "
         << seconds << " seconds" << endl;
    cout << "\tResulting score was: " << s.getScore() << endl;
}

