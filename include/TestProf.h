#ifndef TESTPROF_H
#define TESTPROF_H

#include "TestRunner.h"

/**
 * This class tests the Prof class.
 */
class TestProf : public TestRunner
{
public:
    TestProf(void) : TestRunner("TestProf") { }
protected:
    virtual void testPass(void);
    virtual void testFail(void);
};

#endif // TESTPROF_H