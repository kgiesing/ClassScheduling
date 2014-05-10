#include "../include/TestGeneticScheduleGenerator.h"
#include "../include/TestProfInfo.h"
#include "../include/TestScoreCalculators.h"

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
