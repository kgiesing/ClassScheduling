#ifndef TESTGREEDYSCHEDULEGENERATOR_H
#define TESTGREEDYSCHEDULEGENERATOR_H

#include "TestRunner.h"


class TestGreedyScheduleGenerator : public TestRunner
{
public:
    /** Default constructor */
    TestGreedyScheduleGenerator() : TestRunner("GreedyScheduleGenerator") { }
protected:
    // virtual void preTest(bool);
    virtual void testPass(void);
    virtual void testFail(void);
};

#endif // TESTGREEDYSCHEDULEGENERATOR_H
