#include "../include/TestScheduleWriter.h"
#include "../include/DataCreator.h"
#include "../include/ObjectPrinter.h"
#include "../../include/ScheduleWriter.h"

void TestScheduleWriter::testPass(void)
{
    // Declare variables
    ScheduleWriter* instance;
    Schedule s = DataCreator::createSchedule();
    string filename = "SCHEDULEWRITER_OUTPUT.txt";

    instance = new ScheduleWriter(filename);
    cout << "Successfully created ScheduleWriter object with data:" << endl
         << "\tFilename: \"" << filename << "\"" << endl << "\t";
    ObjectPrinter::print(s, "\t");

    // Test accessors
    cout << "Testing accessors..." << endl;
    cout << "\tgetFilename: " << instance->getFilename() << endl;
    cout << endl;

    // Test mutators
    cout << "Testing mutators..." << endl;
    cout << "\tsetFilename(\"FAKE.txt\")... " << endl;
    instance->setFilename("FAKE.txt");
    cout << "\tsetFieldDelimiter('X')... " << endl;
    // instance->setFieldDelimiter('X');
    cout << "\tsetDelimiter(s)... " << endl;
    instance->setContents(&s);
    cout << endl;

    // Output values after mutating
    cout << "Values after mutating:" << endl;
    cout << "\tgetFilename: " << instance->getFilename() << endl;
    cout << endl;

    delete instance;

    // Re-create object to test generators/specialized member functions
    cout << "Re-creating ScheduleWriter object..." << endl;
    instance = new ScheduleWriter(filename);
    instance->setContents(&s);
    cout << "Testing remaining member functions..." << endl;
    cout << "\twrite:" << endl;
    instance->write();

    // Done
    delete instance;
}
