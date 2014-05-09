#ifndef TESTPROFINFO_H
#define TESTPROFINFO_H

#include "TestRunner.h"


class TestProfInfo : public TestRunner
{
public:
    /** Default constructor */
    TestProfInfo() : TestRunner("ProfInfo") { }
protected:
    // virtual void preTest(bool);
    virtual void testPass(void);
    // virtual void testFail(void);
};

#endif // TESTPROFINFO_H
