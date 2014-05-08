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
    instance = new Course("CS-240", "Programming in C", 30, "012345678", conflicts);
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
        cout << "\n\t\t" << (*it);
    cout << endl;

    // Done
    delete instance;
}

