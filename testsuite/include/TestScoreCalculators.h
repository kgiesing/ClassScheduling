#ifndef TESTSCORECALCULATORS_H
#define TESTSCORECALCULATORS_H

#include "../include/TestRunner.h"

class TestScoreCalculators : public TestRunner
{
public:
    /** Default constructor */
    TestScoreCalculators() : TestRunner("ScoreCalculator") { }
protected:
    // virtual void testPass(void);
    // virtual void testFail(void);
};

#endif // TESTSCORECALCULATORS_H
