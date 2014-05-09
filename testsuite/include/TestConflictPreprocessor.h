#ifndef TESTCONFLICTPREPROCESSOR_H
#define TESTCONFLICTPREPROCESSOR_H

#include "TestRunner.h"


class TestConflictPreprocessor : public TestRunner
{
public:
    /** Default constructor */
    TestConflictPreprocessor() : TestRunner("ConflictPreprocessor") { }
protected:
    virtual void testPass(void);
};

#endif // TESTCONFLICTPREPROCESSOR_H
