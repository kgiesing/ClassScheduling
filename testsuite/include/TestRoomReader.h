#ifndef TESTROOMREADER_H
#define TESTROOMREADER_H

#include "TestFileReaders.h"


class TestRoomReader : public TestFileReaders
{
public:
    /**
     * Constructor.
     * @param Filename for file containing valid data.
     * @param Filename for file containing invalid data.
     */
    TestRoomReader(string, string);
private:
    virtual void runTest(string);
};

#endif // TESTROOMREADER_H
