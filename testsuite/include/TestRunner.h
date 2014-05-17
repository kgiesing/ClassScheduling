#ifndef TESTRUNNER_H
#define TESTRUNNER_H

// Include these here, so subclasses won't have to.
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class TestRunner
{
public:
    /**
     * Constructor.
     * @param Name of the component being tested.
     */
    TestRunner(string component) : _component(component) { }
    /** Virtual destructor. */
    virtual ~TestRunner(void) { }
    /** Returns the name of the component being tested. */
    virtual const string getComponent() const { return _component; }
    /**
     * Runs tests on this component that should pass.
     * This method calls the virtual function testPass(), catching any
     * errors that occur, and printing to std::cerr when they do.
     * @param Whether to run the sub-component tests. Default is true.
     */
    virtual void runPassTests(bool = true);
    /**
     * Runs tests on this component that should fail.
     * This method calls the virtual function testFail(), catching any
     * errors that occur, and printing to std::cerr when they do.
     * @param Whether to run the sub-component tests. Default is true.
     */
    virtual void runFailTests(bool = true);

    /**
     * Runs efficiency tests on this component.
     * This test is for components with methods that will be called repeatedly.
     * The test simply calls each method repeatedly until the number of seconds
     * has elapsed, then outputs the results.
     * Efficiency tests must be explicitly run on a component; it will not run
     * efficiency tests on its sub-components.
     * @param Number of seconds to run the test.
     */
    virtual void runStressTests(unsigned = 5);
protected:
    /**
     * Hook for subclasses to run tests on their sub-components.
     * This method is called by both runPassTests() and runFailTests(),
     * prior to testPass() and testFail() (respectively).
     * @param True if this is a pass test; false if it is a fail test.
     */
    virtual void preTest(bool);
    /**
     * Hook for subclasses to run tests on a specific component. These
     * tests should pass. This method is called by runPassTests().
     * Default implementation simply outputs that there are no pass tests
     * written.
     */
    virtual void testPass(void);
    /**
     * Hook for subclasses to run stress tests on a specific component.
     * Subclasses should call every method they wish to test, over and over
     * again, until the number of seconds has elapsed (per method).
     * This method is called by runStressTests().
     * Default implementation simply outputs that there are no pass tests
     * written.
     * @param Number of seconds to perform each test.
     */
    virtual void testStress(unsigned);
    /**
     * Hook for subclasses to run tests on a specific component. These
     * tests should fail. This method is called by runPassTests(void).
     * Default implementation simply outputs that there are no pass tests
     * written.
     */
    virtual void testFail(void);
private:
    string _component; /**< Name of component being tested. */
};

#endif // TESTRUNNER_H
