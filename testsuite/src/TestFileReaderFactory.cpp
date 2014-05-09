#include "../include/TestFileReaderFactory.h"
#include "../include/TestCourseReader.h"
#include "../include/TestProfReader.h"
#include "../include/TestRoomReader.h"
#include "../include/VectorPrinter.h"
#include "../../include/FileReaderFactory.h"

TestFileReaderFactory::TestFileReaderFactory(string validCourse,
        string invalidCourse, string validProf, string invalidProf,
        string validRoom, string invalidRoom) :
    TestRunner("FileReaderFactory"),
    _validCourse(validCourse),
    _invalidCourse(invalidCourse),
    _validProf(validProf),
    _invalidProf(invalidProf),
    _validRoom(validRoom),
    _invalidRoom(invalidRoom) { }

void TestFileReaderFactory::preTest(bool isPass)
{
    // Test the Readers here
    TestFileReaders* reader;
    reader = new TestCourseReader(_validCourse, _invalidCourse);
    isPass ? reader->runPassTests() : reader->runFailTests();
    delete reader;
    reader = new TestProfReader(_validProf, _invalidProf);
    isPass ? reader->runPassTests() : reader->runFailTests();
    delete reader;
    reader = new TestRoomReader(_validRoom, _invalidRoom);
    isPass ? reader->runPassTests() : reader->runFailTests();
    delete reader;
}

void TestFileReaderFactory::testPass(void)
{
    FileReaderFactory* instance;

    // Run tests on the factory
    instance = new FileReaderFactory();
    // Test accessors
    cout << "Testing accessors..." << endl;
    cout << "\tgetId: " << instance->getDelimiter() << endl;
    cout << endl;

    // Test mutators
    cout << "Testing mutators..." << endl;
    cout << "\tsetId(\"CS-450\")... " << endl;
    instance->setDelimiter('X');
    cout << endl;

    // Output values after mutating
    cout << "Values after mutating:" << endl;
    cout << "\tgetId: " << instance->getDelimiter() << endl;
    cout << endl;

    delete instance;

    // Re-create object to test generators/specialized member functions
    cout << "Re-creating object..." << endl;
    instance = new FileReaderFactory();
    cout << "Testing remaining member functions..." << endl;
    cout << "\tgetCourses: ";
    VectorPrinter::print(instance->getCourses(_validCourse));
    cout << "\tgetProfs: ";
    VectorPrinter::print(instance->getProfs(_validProf));
    cout << "\tgetRooms: ";
    VectorPrinter::print(instance->getRooms(_validRoom));

    // Done
    delete instance;
}

void TestFileReaderFactory::testFail(void)
{
    TestFileReaders* reader;
    FileReaderFactory* instance;

    // Test the Readers first
    reader = new TestCourseReader(_validCourse, _invalidCourse);
    reader->runFailTests();
    delete reader;
    reader = new TestProfReader(_validProf, _invalidProf);
    reader->runFailTests();
    delete reader;
    reader = new TestRoomReader(_validRoom, _invalidRoom);
    reader->runFailTests();
    delete reader;

    // Run tests on the factory
    instance = new FileReaderFactory();

    cout << "Testing remaining member functions..." << endl;
    cout << "\tgetCourses: ";
    VectorPrinter::print(instance->getCourses(_invalidCourse));
    cout << "\tgetProfs: ";
    VectorPrinter::print(instance->getProfs(_invalidProf));
    cout << "\tgetRooms: ";
    VectorPrinter::print(instance->getRooms(_invalidRoom));

    // Done
    delete instance;
}
