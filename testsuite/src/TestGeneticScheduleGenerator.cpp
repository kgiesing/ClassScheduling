#include "../include/TestGeneticScheduleGenerator.h"
#include "../include/DataCreator.h"
#include "../include/ObjectPrinter.h"
#include "../include/TestProfInfo.h"
#include "../include/TestScoreCalculators.h"
#include "../../include/GeneticScheduleGenerator.h"
#include "../../include/LinearScoreCalculator.h"
#include "../../include/WeightedScoreCalculator.h"
#include <ctime>

void TestGeneticScheduleGenerator::preTest(bool isPass)
{
    TestRunner* instance;
    // Test the ProfInfo class here
    instance = new TestProfInfo();
    isPass ? instance->runPassTests() : instance->runFailTests();
    delete instance;

    // Test the ScoreCalculator classes here
    instance = new TestScoreCalculators();
    isPass ? instance->runPassTests() : instance->runFailTests();
    delete instance;
}

void TestGeneticScheduleGenerator::testPass(void)
{
    // Test the greedy schedule generator.
    GeneticScheduleGenerator* instance;
    Schedule* sp;
    ScoreCalculator* sc;

    // Instantiate new Schedule
    cout << "Creating data for GeneticScheduleGenerator constructor..." << endl;
    Schedule s = DataCreator::createSchedule();
    sp = &s;
    sc = new WeightedScoreCalculator();
    long done = time(NULL) + 60;
    cout << "\tScoreCalculator: WeightedScoreCalculator\n\t";
    ObjectPrinter::print(s, "\t");
    cout << "\tTimeout: " << done << endl;
    instance = new GeneticScheduleGenerator(*sc, sp, done);
    cout << "Successfully created GeneticScheduleGenerator object with data" << endl;

    // Test accessors
    cout << "Testing accessors:" << endl;
    cout << "\tgetTimeout: " << instance->getTimeout() << endl;
    cout << "\tgetSchedule: " << endl;
    sp = instance->getSchedule();
    ObjectPrinter::print(*sp, "\t");
    delete sc;
    delete sp;
    delete instance;

    // Instantiate new Schedule
    cout << "Testing same data with different ScoreCalculator..." << endl;
    sp = &s;
    sc = new LinearScoreCalculator();
    cout << "\tScoreCalculator: LinearScoreCalculator" << endl;
    instance = new GeneticScheduleGenerator(*sc, sp, done);
    cout << "Successfully created GeneticScheduleGenerator object with data" << endl;

    // Test accessors
    cout << "Testing accessors:" << endl;
    cout << "\tgetTimeout: " << instance->getTimeout() << endl;
    cout << "\tgetSchedule: " << endl;
    sp = instance->getSchedule();
    ObjectPrinter::print(*sp, "\t");
    delete sc;
    delete sp;
    delete instance;
}
