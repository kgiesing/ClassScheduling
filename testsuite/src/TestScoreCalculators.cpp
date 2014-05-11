#include "../include/TestScoreCalculators.h"
#include "../include/DataCreator.h"
#include "../include/ObjectPrinter.h"
#include "../../include/LinearScoreCalculator.h"
#include "../../include/WeightedScoreCalculator.h"
#include "../../include/Prof.h"
#include "../../include/ProfInfo.h"

void TestScoreCalculators::testPass(void)
{
    ScoreCalculator* sc;

    // Create some fake data for testing
    Prof prof1 = DataCreator::createProf();
    cout << "prof1:" << endl;
    ObjectPrinter::print(prof1);
    ProfInfo p1(prof1);
    p1.setDaysOnCampus(2);
    p1.setNumCourses(3);
    p1.setTotalTime(32);
    cout << "p1:" << endl;
    ObjectPrinter::print(p1, "   ");

    // This ProfInfo differs only in number of days on campus
    Prof prof2 = DataCreator::createProf();
    cout << "prof2:" << endl;
    ObjectPrinter::print(prof2);
    ProfInfo p2(prof2);
    p2.setDaysOnCampus(4);
    p2.setNumCourses(3);
    p2.setTotalTime(32);
    cout << "p2:" << endl;
    ObjectPrinter::print(p2, "   ");

    // Test the weighted version
    sc = new WeightedScoreCalculator();
    cout << "Successfully created WeightedScoreCalculator object" << endl;
    cout << "Weighted score for p1: " << (*sc)(p1) << endl
         << "Weighted score for p2: " << (*sc)(p2) << endl;
    delete sc;

    // Test the linear version
    sc = new LinearScoreCalculator();
    cout << "Successfully created LinearScoreCalculator object" << endl;
    cout << "Linear score for p1: " << (*sc)(p1) << endl
         << "Linear score for p2: " << (*sc)(p2) << endl;
    delete sc;
}
