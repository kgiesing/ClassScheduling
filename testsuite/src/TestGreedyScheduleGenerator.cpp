#include "../include/TestGreedyScheduleGenerator.h"
#include "../include/TestSchedule.h"

void TestGreedyScheduleGenerator::preTest(bool isPass)
{
    // Test the Schedule class here
    TestRunner* instance = new TestSchedule();
    isPass ? instance->runPassTests() : instance->runFailTests();
    delete instance;
}
