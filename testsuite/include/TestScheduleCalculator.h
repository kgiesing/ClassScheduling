#ifndef TESTSCHEDULECALCULATOR_H
#define TESTSCHEDULECALCULATOR_H

#include "TestRunner.h"

class TestScheduleCalculator : public TestRunner
{
    public:
        /** Default constructor */
        TestScheduleCalculator(void) : TestRunner("ScheduleCalculator") { }
    protected:
    // virtual void preTest(bool);
    virtual void testPass(void);
    // virtual void testFail(void);
    virtual void testStress(unsigned);
};

#endif // TESTSCHEDULECALCULATOR_H
