#include <iostream>
#include <string>
#include "../include/TestFileReaderFactory.h"

using namespace std;

// Global constants: valid and invalid test filenames
const string VALID_COURSES = "./res/courses_ok.txt";
const string VALID_PROFS   = "./res/profs_ok.txt";
const string VALID_ROOMS   = "./res/rooms_ok.txt";
// TODO: Create these
const string INVALID_COURSES = "./res/courses_ok.txt";
const string INVALID_PROFS   = "./res/profs_ok.txt";
const string INVALID_ROOMS   = "./res/rooms_ok.txt";

int main()
{
    // Run tests on the FileReaderFactory
    TestFileReaderFactory* reader = new TestFileReaderFactory(VALID_COURSES,
            INVALID_COURSES, VALID_PROFS, INVALID_PROFS, VALID_ROOMS,
            INVALID_ROOMS);
    reader->runPassTests();
    reader->runFailTests();
    delete reader;
}
