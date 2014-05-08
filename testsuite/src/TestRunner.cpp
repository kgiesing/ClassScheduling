#include "../include/TestRunner.h"

void TestRunner::runPassTests(void)
{
    try
    {
        cout << "Running pass tests for " << this->getComponent() << endl;
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
        cout << "Running fail tests for " << this->getComponent() << endl;
        this->testFail();
    }
    catch (...)
    {
        cerr << "Fail test exception in " << this->getComponent() << endl;
    }

}

void TestRunner::testPass(void)
{
    cout << "[No pass tests written for" << this->getComponent() << "]" << endl;
}

void TestRunner::testFail(void)
{
    cout << "[No fail tests written for" << this->getComponent() << "]" << endl;
}

