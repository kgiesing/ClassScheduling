#ifndef TESTCOURSE_H
#define TESTCOURSE_H

#include "TestRunner.h"

/**
 * This class tests the Course class.
 */
class TestCourse : public TestRunner
{
public:
    /** Constructor. */
    TestCourse(void) : TestRunner("Course") { }
protected:
    virtual void testPass(void);
};

#endif // TESTCOURSE_H
