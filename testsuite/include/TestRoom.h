#ifndef TESTROOM_H
#define TESTROOM_H

#include "TestRunner.h"


class TestRoom : public TestRunner
{
public:
    TestRoom() : TestRunner("Room") { }
protected:
    virtual void testPass(void);
};

#endif // TESTROOM_H
