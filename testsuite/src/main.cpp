#include <iostream>
#include <string>
#include "../include/DataCreator.h"
#include "../include/TestConflictPreprocessor.h"
#include "../include/TestFileReaderFactory.h"
#include "../include/TestGeneticScheduleGenerator.h"
#include "../include/TestGreedyScheduleGenerator.h"
#include "../include/TestScheduleWriter.h"
#include "../include/TestScoreCalculators.h"

using namespace std;

// Global constants: valid and invalid test filenames
const string VALID_COURSES = "./res/courses_ok.txt";
const string VALID_PROFS   = "./res/profs_ok.txt";
const string VALID_ROOMS   = "./res/rooms_ok.txt";
const string INVALID_COURSES = "./res/courses_fail.txt";
const string INVALID_PROFS   = "./res/profs_fail.txt";
const string INVALID_ROOMS   = "./res/rooms_fail.txt";

int main()
{
    // Dynamically create invalid data
    DataCreator::createVectorFile(INVALID_COURSES,
                                  DataCreator::createCourse(), 50);
    DataCreator::createVectorFile(INVALID_PROFS,
                                  DataCreator::createProf(), 10);
    DataCreator::createVectorFile(INVALID_ROOMS,
                                  DataCreator::createRoom(), 5);

    TestRunner* instance;

    // Run tests on FileReaderFactory
    instance = new TestFileReaderFactory(VALID_COURSES, INVALID_COURSES,
            VALID_PROFS, INVALID_PROFS, VALID_ROOMS, INVALID_ROOMS);
    instance->runPassTests();
    instance->runFailTests();
    delete instance;

    // Run tests on ConflictPreprocessor
    instance = new  TestConflictPreprocessor();
    instance->runPassTests();
    instance->runFailTests();
    delete instance;

    // Run tests on the GreedyScheduleGenerator
    instance = new TestGreedyScheduleGenerator();
    instance->runPassTests();
    instance->runFailTests();
    delete instance;

    // This should be in Genetic, but run here for now...
    instance = new TestScoreCalculators();
    instance->runPassTests();
    instance->runFailTests();
    delete instance;

    // Run tests on the GeneticScheduleGenerator
    instance = new TestGeneticScheduleGenerator();
    instance->runPassTests();
    instance->runFailTests();
    delete instance;

    // Run tests on the ScheduleWriter
    instance = new  TestScheduleWriter();
    instance->runPassTests();
    instance->runFailTests();
    delete instance;

    // Done
    return 0;
}
