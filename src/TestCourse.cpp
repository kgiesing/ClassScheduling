#include "TestCourse.h"
#include "Course.h"

void testPass(void)
{
    set<string> conflicts;
    // Create a no-arg object
    Course* c = new Course();
    cout << "Successfully created no-arg Course object" << endl;
    delete c;

    // Create a fake course with fake conflicts
    conflicts.add("CS-210");
    conflicts.add("CS-220");
    c = new Course("CS-240", "Programming in C", 30, "012345678", conflicts);
    cout << "Successfully created Course object with data" << endl;

    // Test accessors
    cout << "Testing accessors..." << endl;
    cout << "\tgetId: " << c->getId() << endl;
    cout << "\tgetName: " << c->getName() << endl;
    cout << "\tgetEnrolled: " << c->getEnrolled() << endl;
    cout << "\tgetProfId: " << c->getProfId() << endl;
    cout << "\tgetConflicts: ";
    conflicts = c->getConflicts();
    set<string>::iterator it;
    for (it = conflicts.begin(); it != conflicts.end(); ++it)
        cout << (*it) << " ";
    cout << endl;

    // Test mutators
    cout << "Testing mutators..." << endl;
    cout << "\tsetId(\"CS-450\")... " << endl;
    c->setId("CS-450");
    cout << "\tsetName(\"Compilers I\")... " << endl;
    c->setName("Compilers I");
    cout << "\tsetEnrolled(32)... " << endl;
    c->setEnrolled(32);
    cout << "\tsetProfId(\"987654321\")... " << endl;
    c->setProfId("987654321");
    cout << "\tsetConflicts(conflicts)... ";
    c->setConflicts(conflicts);
    cout << endl;

    // Output values after mutating
    cout << "Values after mutating:" << endl;
    cout << "\tgetId: " << c->getId() << endl;
    cout << "\tgetName: " << c->getName() << endl;
    cout << "\tgetEnrolled: " << c->getEnrolled() << endl;
    cout << "\tgetProfId: " << c->getProfId() << endl;
    cout << "\tgetConflicts: ";
    conflicts = c->getConflicts();
    set<string>::iterator it;
    for (it = conflicts.begin(); it != conflicts.end(); ++it)
        cout << "\n\t\t" << (*it);
    cout << endl;

    // Done
    delete c;
}

