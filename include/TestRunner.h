#ifndef TESTRUNNER_H
#define TESTRUNNER_H

// Include these here, so subclasses won't have to.
#include <iostream>

using std::cerr;
using std::endl;
using std::cout;

class TestRunner
{
    public:
        /**
         * Constructor.
         * @param Name of the component being tested.
         */
        TestRunner(string component) : _component(component) { }
        /** Returns the name of the component being tested. */
        virtual string getComponent() { return _component; }
        /**
         * Runs tests on this component that should pass.
         * This method calls the virtual function testPass(), catching any
         * errors that occur, and printing to std::cerr when they do.
         */
        virtual void runPassTests(void);
        /**
         * Runs tests on this component that should fail.
         * This method calls the virtual function testFail(), catching any
         * errors that occur, and printing to std::cerr when they do.
         */
        virtual void runFailTests(void);
    protected:
        /**
         * Hook for subclasses to run tests on a specific component. These
         * tests should pass. This method is called by runPassTests(void).
         */
        virtual void testPass(void) = 0;
        /**
         * Hook for subclasses to run tests on a specific component. These
         * tests should fail. This method is called by runPassTests(void).
         */
        virtual void testFail(void) = 0;
    private:
        string _component; /**< Name of component being tested. */
};

#endif // TESTRUNNER_H
