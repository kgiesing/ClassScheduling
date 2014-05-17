#ifndef TESTSCHEDULE_H
#define TESTSCHEDULE_H

#include "../include/TestRunner.h"

class TestSchedule : public TestRunner
{
public:
    /** Default constructor */
    TestSchedule() : TestRunner("Schedule") { }
protected:
    // virtual void preTest(bool);
    virtual void testPass(void);
    virtual void testFail(void);
    virtual void testStress(unsigned);
};

#endif // TESTSCHEDULE_H
