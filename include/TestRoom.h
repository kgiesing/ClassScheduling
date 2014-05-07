#ifndef TESTROOM_H
#define TESTROOM_H

#include "TestRunner.h"


class TestRoom : public TestRunner
{
public:
    TestRoom() : TestRunner("TestRoom") { }
protected:
    virtual void testPass(void);
    virtual void testFail(void);
};

#endif // TESTROOM_H
