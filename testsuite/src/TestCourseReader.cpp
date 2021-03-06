#include "../include/TestCourseReader.h"
#include "../include/TestCourse.h"
#include "../include/VectorPrinter.h"
#include "../../include/CourseReader.h"

TestCourseReader::TestCourseReader(string valid, string invalid) :
    TestFileReaders("CourseReader", valid, invalid) { }

void TestCourseReader::preTest(bool isPass)
{
    // Run pass or fail tests, depending upon whether isPass is true
    TestCourse* test = new TestCourse();
    isPass ? test->runPassTests() : test->runFailTests();
    delete test;
}

void TestCourseReader::runTest(string filename)
{
    // Create a fake object
    CourseReader* instance = new CourseReader(filename);
    cout << "Successfully created CourseReader object with data" << endl;

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
    cout << "Re-creating CourseReader object..." << endl;
    instance = new CourseReader(filename);
    cout << "Testing remaining member functions..." << endl;
    cout << "\tread:" << endl;
    VectorPrinter::print(instance->read(), "\t");

    // Done
    delete instance;
}
