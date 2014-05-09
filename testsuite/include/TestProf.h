#ifndef TESTPROF_H
#define TESTPROF_H

#include "TestRunner.h"

/**
 * This class tests the Prof class.
 */
class TestProf : public TestRunner
{
public:
    TestProf(void) : TestRunner("Prof") { }
protected:
    virtual void testPass(void);
};

#endif // TESTPROF_H
