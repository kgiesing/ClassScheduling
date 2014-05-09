#ifndef TESTPROFREADER_H
#define TESTPROFREADER_H

#include "TestFileReaders.h"


class TestProfReader : public TestFileReaders
{
public:
    /**
     * Constructor.
     * @param Filename for file containing valid data.
     * @param Filename for file containing invalid data.
     */
    TestProfReader(string, string);
private:
    virtual void preTest(bool);
    virtual void runTest(string);
};

#endif // TESTPROFREADER_H
