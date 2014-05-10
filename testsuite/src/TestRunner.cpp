#include "../include/TestRunner.h"

void TestRunner::runPassTests(void)
{
    cout << "Running pass tests for sub-components of "
         << this->getComponent() << "...\n";
    this->preTest(true);
    cout << "Pass tests for sub-components of " << this->getComponent()
         << " complete.\n\n";
    try
    {
        cout << "Running pass tests for " << this->getComponent() << "...\n";
        this->testPass();
        cout << "Pass tests for " << this->getComponent() << " complete.\n\n";
    }
    catch (...)
    {
        cerr << "Pass test exception in " << this->getComponent() << endl;
    }
}

void TestRunner::runFailTests(void)
{
    cout << "Running fail tests for sub-components of "
         << this->getComponent() << "...\n";
    this->preTest(false);
    cout << "Fail tests for sub-components of " << this->getComponent()
         << " complete.\n\n";
    try
    {
        cout << "Running fail tests for " << this->getComponent() << "...\n";
        this->testFail();
        cout << "Fail tests for " << this->getComponent() << " complete.\n\n";
    }
    catch (...)
    {
        cerr << "Fail test exception in " << this->getComponent() << endl;
    }

}

void TestRunner::preTest(bool)
{
    cout << "\t[No sub-component tests written for " << this->getComponent()
         << "]" << endl;
}

void TestRunner::testPass(void)
{
    cout << "\t[No pass tests written for " << this->getComponent() << "]"
         << endl;
}

void TestRunner::testFail(void)
{
    cout << "\t[No fail tests written for " << this->getComponent() << "]"
         << endl;
}
