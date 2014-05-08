#include "../include/TestProfReader.h"
#include "../include/TestProf.h"
#include "../../include/ProfReader.h"

TestProfReader::TestProfReader(string valid, string invalid) :
    TestFileReaders("TestProfReader", valid, invalid) { }

void TestProfReader::runTest(string filename)
{
    // Run pass or fail tests, depending upon whether filename is _valid
    TestProf* test = new TestProf();
    (filename == _valid) ? test->runPassTests() : test->runFailTests();
    delete test;

    // Create a fake object
    ProfReader* instance = new ProfReader(filename);
    cout << "Successfully created ProfReader object with data" << endl;

    // Test accessors
    cout << "Testing accessors..." << endl;
    cout << "\tgetFilename: " << instance->getFilename() << endl;
    cout << "\tgetDelimiter: " << instance->getDelimiter() << endl;
    cout << endl;

    // Test mutators
    cout << "Testing mutators..." << endl;
    cout << "\tsetFilename(\"FAKE.txt\")... " << endl;
    instance->setFilename("FAKE.txt");
    cout << "\tsetDelimiter('X')... " << endl;
    instance->setDelimiter('X');
    cout << endl;

    // Output values after mutating
    cout << "Values after mutating:" << endl;
    cout << "\tgetFilename: " << instance->getFilename() << endl;
    cout << "\tgetDelimiter: " << instance->getDelimiter() << endl;
    cout << endl;

    delete instance;

    // Re-create object to test generators/specialized member functions
    cout << "Re-creating ProfReader object..." << endl;
    instance = new ProfReader(filename);
    cout << "Testing remaining member functions..." << endl;
    cout << "\tread: " << endl;
    std::vector<Prof> courses = instance->read();
    for (unsigned i = 0; i < courses.size(); i++)
        cout << "\n\t\t" << courses[i].getId();
    cout << endl;

    // Done
    delete instance;
}


