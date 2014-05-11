#include "../include/TestProfInfo.h"
#include "../include/DataCreator.h"
#include "../include/ObjectPrinter.h"
#include "../../include/Prof.h"
#include "../../include/ProfInfo.h"

void TestProfInfo::testPass(void)
{
    // Create a fake object
    Prof p = DataCreator::createProf();
    ProfInfo* instance = new ProfInfo(p);
    cout << "Successfully created ProfInfo object with Prof data:" << endl;
    ObjectPrinter::print(*instance, "\t");

    // Test accessors
    cout << "Testing accessors..." << endl;
    cout << "\tgetDaysOnCampus: " << instance->getDaysOnCampus() << endl;
    cout << "\tgetNumCourses: " << instance->getNumCourses() << endl;
    cout << "\tgetScore: " << instance->getScore() << endl;
    cout << "\tgetTotalTime: " << instance->getTotalTime() << endl;
    cout << "\tgetProf returns prof with ID: " << instance->getProf().getId()
         << endl;

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

    // Output values after mutating
    cout << "Values after mutating:" << endl;
    ObjectPrinter::print(*instance, "\t");

    delete instance;
}
