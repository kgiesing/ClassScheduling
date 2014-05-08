#include "../include/TestFileReaderFactory.h"
#include "../include/TestCourseReader.h"
#include "../include/TestProfReader.h"
#include "../include/TestRoomReader.h"
#include "../../include/FileReaderFactory.h"

TestFileReaderFactory::TestFileReaderFactory(string validCourse,
        string invalidCourse, string validProf, string invalidProf,
        string validRoom, string invalidRoom) :
    TestRunner("TestFileReaderFactory"),
    _validCourse(validCourse),
    _invalidCourse(invalidCourse),
    _validProf(validProf),
    _invalidProf(invalidProf),
    _validRoom(validRoom),
    _invalidRoom(invalidRoom) { }

void TestFileReaderFactory::testPass(void)
{
    TestFileReaders* reader;
    FileReaderFactory* instance;

    // Test the Readers first
    reader = new TestCourseReader(_validCourse, _invalidCourse);
    reader->runPassTests();
    delete reader;
    reader = new TestProfReader(_validProf, _invalidProf);
    reader->runPassTests();
    delete reader;
    reader = new TestRoomReader(_validRoom, _invalidRoom);
    reader->runPassTests();
    delete reader;

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
    instance = new FileReaderFactory(filename);
    cout << "Testing remaining member functions..." << endl;
    cout << "\tgetCourses: " << endl;
    std::vector<Course> courses = instance->getCourses(_validCourse);
    for (unsigned i = 0; i < courses.size(); i++)
        cout << "\n\t\t" << courses[i].getId();
    cout << endl;
    cout << "\tgetProfs: " << endl;
    std::vector<Prof> profs = instance->getProfs(_validProf);
    for (unsigned i = 0; i < profs.size(); i++)
        cout << "\n\t\t" << profs[i].getId();
    cout << endl;
    cout << "\tgetProfs: " << endl;
    std::vector<Room> rooms = instance->getRooms(_validRoom);
    for (unsigned i = 0; i < rooms.size(); i++)
        cout << "\n\t\t" << rooms[i].getId();
    cout << endl;

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
    cout << "\tgetCourses: " << endl;
    std::vector<Course> courses = instance->getCourses(_invalidCourse);
    for (unsigned i = 0; i < courses.size(); i++)
        cout << "\n\t\t" << courses[i].getId();
    cout << endl;
    cout << "\tgetProfs: " << endl;
    std::vector<Prof> profs = instance->getProfs(_invalidProf);
    for (unsigned i = 0; i < profs.size(); i++)
        cout << "\n\t\t" << profs[i].getId();
    cout << endl;
    cout << "\tgetProfs: " << endl;
    std::vector<Room> rooms = instance->getRooms(_invalidRoom);
    for (unsigned i = 0; i < rooms.size(); i++)
        cout << "\n\t\t" << rooms[i].getId();
    cout << endl;

    // Done
    delete instance;
}
