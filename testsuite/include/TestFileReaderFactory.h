#ifndef TESTFILEREADERFACTORY_H
#define TESTFILEREADERFACTORY_H

#include "TestRunner.h"


class TestFileReaderFactory : public TestRunner
{
public:
    /** Constructor. */
    TestFileReaderFactory(string, string, string, string, string, string);
protected:
    virtual void testPass(void);
    virtual void testFail(void);
private:
    string _validCourse;
    string _invalidCourse;
    string _validProf;
    string _invalidProf;
    string _validRoom;
    string _invalidRoom;
};

#endif // TESTFILEREADERFACTORY_H
