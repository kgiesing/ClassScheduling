#ifndef TESTCOURSEREADER_H
#define TESTCOURSEREADER_H

#include "TestRunner.h"

/**
 * This class tests the Prof class.
 */
class TestCourseReader : public TestRunner
{
public:
    /**
     * Constructor.
     * @param Filename for file containing valid data.
     * @param Filename for file containing invalid data.
     *
     */
    TestCourseReader(string, string);
protected:
    virtual void testPass(void);
    virtual void testFail(void);
private:
    /**
     * Helper function. Runs exactly the same tests with different filenames.
     * @param Filename to test; either _valid or _invalid.
     */
    void runTest(string);
    string _valid;
    string _invalid;
};

#endif // TESTCOURSEREADER_H
