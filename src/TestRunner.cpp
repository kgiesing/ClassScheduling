#include "../includes/TestRunner.h"

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
