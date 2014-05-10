#include "../include/TestProfInfo.h"
#include "../include/DataCreator.h"
#include "../../include/Prof.h"
#include "../../include/ProfInfo.h"

void TestProfInfo::testPass(void)
{
    // Create a fake object
    Prof p = DataCreator::createProf();
    ProfInfo* instance = new ProfInfo(p);
    cout << "Successfully created ProfInfo object with Prof data:" << endl;
    cout << "\tProf: {ID:" << p.getId()
         << ", first:" << p.getFirstName()
         << ", last:" << p.getLastName()
         << "}" << endl;

    // Test accessors
    cout << "Testing accessors..." << endl;
    cout << "\tgetDaysOnCampus: " << instance->getDaysOnCampus() << endl;
    cout << "\tgetNumCourses: " << instance->getNumCourses() << endl;
    cout << "\tgetScore: " << instance->getScore() << endl;
    cout << "\tgetTotalTime: " << instance->getTotalTime() << endl;
    cout << "\tgetProf returns prof with ID: " << instance->getProf().getId()
         << endl;
    cout << endl;

    // Test mutators
    cout << "Testing mutators..." << endl;
    cout << "\tsetDaysOnCampus(4)... " << endl;
    instance->setDaysOnCampus(4);
    cout << "\tsetNumCourses(3)... " << endl;
    instance->setNumCourses(3);
    cout << "\tsetScore(2.0)... " << endl;
    instance->setScore(2.0);
    cout << "\tsetTotalTime(12)... " << endl;
    instance->setTotalTime(12);
    cout << endl;

    // Output values after mutating
    cout << "Values after mutating:" << endl;
    cout << "\tgetDaysOnCampus: " << instance->getDaysOnCampus() << endl;
    cout << "\tgetNumCourses: " << instance->getNumCourses() << endl;
    cout << "\tgetScore: " << instance->getScore() << endl;
    cout << "\tgetTotalTime: " << instance->getTotalTime() << endl;
    cout << "\tgetProf returns prof with ID: " << instance->getProf().getId()
         << endl;
    cout << endl;

    delete instance;
}
