#ifndef TESTSCORECALCULATORS_H
#define TESTSCORECALCULATORS_H

#include "TestRunner.h"

class TestScoreCalculators : public TestRunner
{
public:
    /** Default constructor */
    TestScoreCalculators() : TestRunner("ScoreCalculator") { }
protected:
    // virtual void preTest(bool);
    virtual void testPass(void);
    // virtual void testFail(void);
};

#endif // TESTSCORECALCULATORS_H
