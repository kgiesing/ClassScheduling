#include "../include/TestCourseReader.h"
#include "../../include/CourseReader.h"

TestCourseReader::TestCourseReader(string valid, string invalid) :
    TestRunner("TestCourseReader"), _valid(valid), _invalid(invalid) { }

void TestCourseReader::testPass(void)
{
    runTest(_valid);
}

void TestCourseReader::testFail(void)
{
    runTest(_invalid);
}

void TestCourseReader::runTest(string filename)
{
    // Create a fake object
    CourseReader* instance = new CourseReader(_invalid);
    cout << "Successfully created CourseReader object with data" << endl;

    // Test accessors
    cout << "Testing accessors..." << endl;
    cout << "\tgetFilename: " << instance->getFileName() << endl;
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
    cout << "\tgetFilename: " << instance->getFileName() << endl;
    cout << "\tgetDelimiter: " << instance->getDelimiter() << endl;
    cout << endl;

    delete instance;

    // Re-create object to test generators/specialized member functions
    cout << "Re-creating CourseReader object..." << endl;
    instance = new CourseReader(_invalid);
    cout << "Testing remaining member functions..." << endl;
    cout << "\tread: " << endl;
    std::vector<Course> courses = instance->read();
    for (int i = 0; i < courses.size(); i++)
        cout << "\n\t\t" << courses[i].getId();
    cout << endl;

    // Done
    delete instance;
}
