#ifndef TESTCOURSE_H
#define TESTCOURSE_H

#include TestRunner.h


class TestCourse : public TestRunner
{
public:
    TestCourse() : TestRunner("TestCourse") { }
protected:
    virtual void testPass(void);
    virtual void testFail(void);
};

#endif // TESTCOURSE_H
