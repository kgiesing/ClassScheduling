#include "../include/TestRoomReader.h"
#include "../include/TestRoom.h"
#include "../include/VectorPrinter.h"
#include "../../include/RoomReader.h"

TestRoomReader::TestRoomReader(string valid, string invalid) :
    TestFileReaders("RoomReader", valid, invalid) { }

void TestRoomReader::preTest(bool isPass)
{
    // Run pass or fail tests, depending upon whether filename is _valid
    TestRoom* test = new TestRoom();
    isPass ? test->runPassTests() : test->runFailTests();
    delete test;
}

void TestRoomReader::runTest(string filename)
{
    // Create a fake object
    RoomReader* instance = new RoomReader(filename);
    cout << "Successfully created RoomReader object with data" << endl;

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
    cout << "Re-creating RoomReader object..." << endl;
    instance = new RoomReader(filename);
    cout << "Testing remaining member functions..." << endl;
    cout << "\tread:" << endl;
    VectorPrinter::print(instance->read(), "\t");

    // Done
    delete instance;
}
