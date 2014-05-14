#ifndef TESTGENETICSCHEDULEGENERATOR_H
#define TESTGENETICSCHEDULEGENERATOR_H

#include "TestRunner.h"


class TestGeneticScheduleGenerator : public TestRunner
{
public:
    /** Default constructor */
    TestGeneticScheduleGenerator() :
        TestRunner("GeneticScheduleGenerator") { }
protected:
    virtual void preTest(bool);
    virtual void testPass(void);
    // virtual void testFail(void);
};

#endif // TESTGENETICSCHEDULEGENERATOR_H
