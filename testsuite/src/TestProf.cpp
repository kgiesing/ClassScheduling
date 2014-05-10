#include "../include/TestProf.h"
#include "../../include/Prof.h"

void TestProf::testPass(void)
{
    // Create a no-arg object
    Prof* instance = new Prof();
    cout << "Successfully created no-arg Prof object" << endl;
    delete instance;

    // Create a fake object
    instance = new Prof("012345678", "John", "Doe");
    cout << "Successfully created Prof object with data" << endl;

    // Test accessors
    cout << "Testing accessors..." << endl;
    cout << "\tgetId: " << instance->getId() << endl;
    cout << "\tgetFirstName: " << instance->getFirstName() << endl;
    cout << "\tgetLastName: " << instance->getLastName() << endl;
    cout << endl;

    // Test mutators
    cout << "Testing mutators..." << endl;
    cout << "\tsetId(\"987654321\")... " << endl;
    instance->setId("987654321");
    cout << "\tsetFirstName(\"Jane\")... " << endl;
    instance->setFirstName("Jane");
    cout << "\tsetLastName(\"Dill\")... " << endl;
    instance->setLastName("Dill");
    cout << endl;

    // Output values after mutating
    cout << "Values after mutating:" << endl;
    cout << "\tgetId: " << instance->getId() << endl;
    cout << "\tgetFirstName: " << instance->getFirstName() << endl;
    cout << "\tgetLastName: " << instance->getLastName() << endl;

    // Test comparison operators
    cout << "Creating second object to test comparison operators..." << endl;
    Prof second(instance->getId(), "Greg", "Deer");
    cout << "Second object:" << endl;
    cout << "\tgetId: " << second.getId() << endl;
    cout << "\tgetFirstName: " << second.getFirstName() << endl;
    cout << "\tgetLastName: " << second.getLastName() << endl;

    // Output result of comparison operators
    cout << "Comparisons:" << endl;
    cout << "\tfirst == second returns: " << (*instance == second) << endl;
    cout << "\tfirst != second returns: " << (*instance != second) << endl;
    cout << "\tfirst <  second returns: " << (*instance < second) << endl;
    cout << "\tfirst <= second returns: " << (*instance <= second) << endl;
    cout << "\tfirst >  second returns: " << (*instance > second) << endl;
    cout << "\tfirst >= second returns: " << (*instance >= second) << endl;

    cout << "Modifying second object to test comparison operators..." << endl;
    second.setId("15263748");
    cout << "\tSecond object ID is now:" << second.getId() << endl;

    // Output result of comparison operators
    cout << "Comparisons:" << endl;
    cout << "\tfirst == second returns: " << (*instance == second) << endl;
    cout << "\tfirst != second returns: " << (*instance != second) << endl;
    cout << "\tfirst <  second returns: " << (*instance < second) << endl;
    cout << "\tfirst <= second returns: " << (*instance <= second) << endl;
    cout << "\tfirst >  second returns: " << (*instance > second) << endl;
    cout << "\tfirst >= second returns: " << (*instance >= second) << endl;

    delete instance;
}
