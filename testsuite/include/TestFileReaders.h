#ifndef TESTFILEREADERS_H
#define TESTFILEREADERS_H

#include "TestRunner.h"


class TestFileReaders : public TestRunner
{
public:
    /**
     * Constructor.
     * @param Filename for file containing valid data.
     * @param Filename for file containing invalid data.
     *
     */
    TestFileReaders(string component, string valid, string invalid) :
        TestRunner(component), _valid(valid), _invalid(invalid) { }
protected:
    /**
     * Pure virtual helper function. Runs exactly the same tests with different
     * filenames. Subclasses need only implement this method.
     * @param Filename to test; either _valid or _invalid.
     */
    virtual void runTest(string) = 0;
    virtual void testPass(void) { this->runTest(_valid); }
    virtual void testFail(void) { this->runTest(_invalid); }
    string _valid;
    string _invalid;
};

#endif // TESTFILEREADERS_H
