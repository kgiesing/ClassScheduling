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
    cout << "\tgetDelimiter: " << instance->getDelimiter() << endl;
    cout << endl;

    // Test mutators
    cout << "Testing mutators..." << endl;
    cout << "\tsetDelimiter(\'X\')... " << endl;
    instance->setDelimiter('X');
    cout << endl;

    // Output values after mutating
    cout << "Values after mutating:" << endl;
    cout << "\tgetDelimiter: " << instance->getDelimiter() << endl;
    cout << endl;

    delete instance;

    // Re-create object to test generators/specialized member functions
    cout << "Re-creating object..." << endl;
    instance = new FileReaderFactory();
    cout << "Testing remaining member functions..." << endl;
    cout << "\tgetCourses: " << endl;
    VectorPrinter::print(instance->getCourses(_validCourse), "\t");
    cout << "\tgetProfs: " << endl;
    VectorPrinter::print(instance->getProfs(_validProf), "\t");
    cout << "\tgetRooms: " << endl;
    VectorPrinter::print(instance->getRooms(_validRoom), "\t");

    // Done
    delete instance;
}

void TestFileReaderFactory::testFail(void)
{
    FileReaderFactory* instance;

    // Run tests on the factory
    instance = new FileReaderFactory();

    cout << "Testing remaining member functions..." << endl;
    cout << "\tgetCourses:" << endl;
    VectorPrinter::print(instance->getCourses(_invalidCourse), "\t");
    cout << "\tgetProfs:" << endl;
    VectorPrinter::print(instance->getProfs(_invalidProf), "\t");
    cout << "\tgetRooms:" << endl;
    VectorPrinter::print(instance->getRooms(_invalidRoom), "\t");

    // Done
    delete instance;
}
