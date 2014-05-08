#include "../include/TestRoom.h"
#include "../../include/Room.h"

void TestRoom::testPass(void)
{
    // Create a no-arg object
    Room* instance = new Room();
    cout << "Successfully created no-arg Room object" << endl;
    delete instance;

    // Create a fake object
    instance = new Room("M-02-404", 50);
    cout << "Successfully created Room object with data" << endl;

    // Test accessors
    cout << "Testing accessors..." << endl;
    cout << "\tgetId: " << instance->getId() << endl;
    cout << "\tgetCapacity: " << instance->getCapacity() << endl;
    cout << endl;

    // Test mutators
    cout << "Testing mutators..." << endl;
    cout << "\tsetId(\"987654321\")... " << endl;
    instance->setId("987654321");
    cout << "\tsetCapacity(60)... " << endl;
    instance->setCapacity(60);
    cout << endl;

    // Output values after mutating
    cout << "Values after mutating:" << endl;
    cout << "\tgetId: " << instance->getId() << endl;
    cout << "\tgetCapacity: " << instance->getCapacity() << endl;
    cout << endl;
    delete instance;
}
