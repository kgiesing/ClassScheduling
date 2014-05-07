#include "../includes/TestRunner.h"
#include <iostream>

using std::cerr;
using std::endl;

void TestRunner::runPassTests(void)
{
    try
    {
        this->testPass();
    }
    catch (...)
    {
        cerr << "Pass test exception in " << this->getComponent() << endl;
    }
}

void TestRunner::runFailTests(void)
{
    try
    {
        this->testFail();
    }
    catch (...)
    {
        cerr << "Fail test exception in " << this->getComponent() << endl;
    }

}
