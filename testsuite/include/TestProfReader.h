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
     *
     */
    TestProfReader(string, string);
private:
    /**
     * Helper function. Runs exactly the same tests with different filenames.
     * @param Filename to test; either _valid or _invalid.
     */
    virtual void runTest(string);
    string _valid;
    string _invalid;
};

#endif // TESTPROFREADER_H
