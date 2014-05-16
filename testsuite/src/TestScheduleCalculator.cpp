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
    ScoreCalculator* linear = new LinearScoreCalculator();
    ScoreCalculator* weighted = new WeightedScoreCalculator();

    // Output sample data
    cout << "Test data: "
         << "\n\tlinear: LinearScoreCalculator"
         << "\n\tweighted: WeightedScoreCalculator\n\r";
    ObjectPrinter::print(s, "\t");

    // Test static members
    cout << "Testing static members..." << endl;
    cout << "\tcalculateScore(s, linear): "
         << ScheduleCalculator::calculateScore(&s, *linear) << endl;
    cout << "\tcalculateScore(s, weighted): "
         << ScheduleCalculator::calculateScore(&s, *weighted) << endl;
    cout << endl;
}
