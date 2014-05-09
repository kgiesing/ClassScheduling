#ifndef TESTCOURSEREADER_H
#define TESTCOURSEREADER_H

#include "TestFileReaders.h"

/**
 * This class tests the Prof class.
 */
class TestCourseReader : public TestFileReaders
{
public:
    /**
     * Constructor.
     * @param Filename for file containing valid data.
     * @param Filename for file containing invalid data.
     */
    TestCourseReader(string, string);
private:
    virtual void preTest(bool);
    virtual void runTest(string);
};

#endif // TESTCOURSEREADER_H
