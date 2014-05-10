#include "TestCourse.h"
#include "../../include/Course.h"

void TestCourse::testPass(void)
{
    set<string> conflicts;
    set<string>::iterator it;
    Course* instance;
    // Create a no-arg object
    instance = new Course();
    cout << "Successfully created no-arg Course object" << endl;
    delete instance;

    // Create a fake course with fake conflicts
    conflicts.insert("CS-210");
    conflicts.insert("CS-220");
    instance = new Course("CS-240", "Programming in C", "012345678", 30, 2,
                          conflicts);
    cout << "Successfully created Course object with data" << endl;

    // Test accessors
    cout << "Testing accessors..." << endl;
    cout << "\tgetId: " << instance->getId() << endl;
    cout << "\tgetName: " << instance->getName() << endl;
    cout << "\tgetEnrolled: " << instance->getEnrolled() << endl;
    cout << "\tgetProfId: " << instance->getProfId() << endl;
    cout << "\tgetConflicts: ";
    conflicts = instance->getConflicts();
    for (it = conflicts.begin(); it != conflicts.end(); ++it)
        cout << (*it) << " ";
    cout << endl;

    // Test mutators
    cout << "Testing mutators..." << endl;
    cout << "\tsetId(\"CS-450\")... " << endl;
    instance->setId("CS-450");
    cout << "\tsetName(\"Compilers I\")... " << endl;
    instance->setName("Compilers I");
    cout << "\tsetEnrolled(32)... " << endl;
    instance->setEnrolled(32);
    cout << "\tsetProfId(\"987654321\")... " << endl;
    instance->setProfId("987654321");
    cout << "\tsetConflicts(conflicts)... ";
    instance->setConflicts(conflicts);
    cout << endl;

    // Output values after mutating
    cout << "Values after mutating:" << endl;
    cout << "\tgetId: " << instance->getId() << endl;
    cout << "\tgetName: " << instance->getName() << endl;
    cout << "\tgetEnrolled: " << instance->getEnrolled() << endl;
    cout << "\tgetProfId: " << instance->getProfId() << endl;
    cout << "\tgetConflicts: ";
    conflicts = instance->getConflicts();
    for (it = conflicts.begin(); it != conflicts.end(); ++it)
        cout << (*it) << " ";
    cout << endl;

    // Test comparison operators
    cout << "Creating second object to test comparison operators..." << endl;
    Course second(instance->getId(), "Compilers II: Compiler Boogaloo",
                  "456780123", 25, 4, conflicts);
    cout << "Second object:" << endl;
    cout << "\tgetId: " << second.getId() << endl;
    cout << "\tgetName: " << second.getName() << endl;
    cout << "\tgetEnrolled: " << second.getEnrolled() << endl;
    cout << "\tgetProfId: " << second.getProfId() << endl;
    cout << "\tgetConflicts: ";
    conflicts = second.getConflicts();
    for (it = conflicts.begin(); it != conflicts.end(); ++it)
        cout << (*it) << " ";
    cout << endl;

    // Output result of comparison operators
    cout << "Comparisons:" << endl;
    cout << "\tfirst == second returns: " << (*instance == second) << endl;
    cout << "\tfirst != second returns: " << (*instance != second) << endl;
    cout << "\tfirst <  second returns: " << (*instance < second) << endl;
    cout << "\tfirst <= second returns: " << (*instance <= second) << endl;
    cout << "\tfirst >  second returns: " << (*instance > second) << endl;
    cout << "\tfirst >= second returns: " << (*instance >= second) << endl;

    cout << "Modifying second object to test comparison operators..." << endl;
    second.setId("CS-444");
    cout << "\tSecond object ID is now:" << second.getId() << endl;

    // Output result of comparison operators
    cout << "Comparisons:" << endl;
    cout << "\tfirst == second returns: " << (*instance == second) << endl;
    cout << "\tfirst != second returns: " << (*instance != second) << endl;
    cout << "\tfirst <  second returns: " << (*instance < second) << endl;
    cout << "\tfirst <= second returns: " << (*instance <= second) << endl;
    cout << "\tfirst >  second returns: " << (*instance > second) << endl;
    cout << "\tfirst >= second returns: " << (*instance >= second) << endl;

    // Done
    delete instance;
}

