#ifndef TESTSCHEDULEWRITER_H
#define TESTSCHEDULEWRITER_H

#include "TestRunner.h"


class TestScheduleWriter : public TestRunner
{
public:
    /** Default constructor */
    TestScheduleWriter() : TestRunner("ScheduleWriter") { }
protected:
    // virtual void testPass(void);
    // virtual void testFail(void);
};

#endif // TESTSCHEDULEWRITER_H
