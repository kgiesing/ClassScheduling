#include "../include/TestRunner.h"
#include <exception>

void TestRunner::runPassTests(bool runPre)
{
    if (runPre)
    {
        cout << "Running pass tests for sub-components of "
             << this->getComponent() << "...\n";
        this->preTest(true);
        cout << "Pass tests for sub-components of " << this->getComponent()
             << " complete.\n\n";
    }
    else
        cout << "[Skipping pass tests for sub-components of "
             << this->getComponent() << "]" << endl;
    try
    {
        cout << "Running pass tests for " << this->getComponent() << "...\n";
        this->testPass();
        cout << "Pass tests for " << this->getComponent() << " complete.\n\n";
    }
    catch (std::exception& e)
    {
        cerr << endl << "****************************************"
             << endl << "Pass test exception in " << this->getComponent()
             << ":\n\t" << e.what()
             << endl << "****************************************" << endl;
    }
    catch (...)
    {
        cerr << endl << "****************************************"
             << endl << "Pass test exception in " << this->getComponent()
             << endl << "****************************************" << endl;
    }
}

void TestRunner::runFailTests(bool runPre)
{
    if (runPre)
    {
        cout << "Running fail tests for sub-components of "
             << this->getComponent() << "...\n";
        this->preTest(false);
        cout << "Fail tests for sub-components of " << this->getComponent()
             << " complete.\n\n";
    }
    else
        cout << "[Skipping fail tests for sub-components of "
             << this->getComponent() << "]" << endl;
    try
    {
        cout << "Running fail tests for " << this->getComponent() << "...\n";
        this->testFail();
        cout << "Fail tests for " << this->getComponent() << " complete.\n\n";
    }
    catch (std::exception& e)
    {
        cerr << endl << "****************************************"
             << endl << "Fail test exception in " << this->getComponent()
             << ":\n\t" << e.what()
             << endl << "****************************************" << endl;
    }
    catch (...)
    {
        cerr << endl << "****************************************"
             << endl << "Fail test exception in " << this->getComponent()
             << endl << "****************************************" << endl;
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
