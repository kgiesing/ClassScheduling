#include <iostream>
#include <set>
#include <string>
#include "../include/DataCreator.h"
#include "../include/TestConflictPreprocessor.h"
#include "../include/TestFileReaderFactory.h"
#include "../include/TestGeneticScheduleGenerator.h"
#include "../include/TestGreedyScheduleGenerator.h"
#include "../include/TestSchedule.h"
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

/**
 * Main method for the test suite.
 * Accepts any of the following command-line arguments, in any order.
 * Passing no arguments results in tests being run for all components.
 * - -i: run tests on the input component (Reader classes)
 * - -n: run tests on the geNetic schedule generator
 * - -o: (lower-case "oh"): run tests on the output component (Writer)
 * - -p: run tests on the preprocessor component
 * - -r: run tests on the gReedy schedule generator
 * - -s: run tests on the schedule object
 * (Note: the colon, ":", is not part of the argument.)
 * @param Argument count
 * @param Argument values
 * @return 0 on success; non-zero on failure
 */
int main(int argc, char* argv[])
{
    TestRunner* instance;

    // Parse the command line arguments
    set<string> args;
    if (argc < 2)
    {
        // No arguments; parse all
        args.insert("-i");
        args.insert("-n");
        args.insert("-o");
        args.insert("-p");
        args.insert("-r");
        args.insert("-s");
    }
    for (int i = 1; i < argc; i++)
        args.insert(argv[i]);

    if(args.find("-i") != args.end())
    {
        // Dynamically create invalid data
        DataCreator::createVectorFile(INVALID_COURSES,
                DataCreator::createCourse(), 50);
        DataCreator::createVectorFile(INVALID_PROFS,
                DataCreator::createProf(), 10);
        DataCreator::createVectorFile(INVALID_ROOMS,
                DataCreator::createRoom(), 5);

        // Run tests on FileReaderFactory
        instance = new TestFileReaderFactory(VALID_COURSES, INVALID_COURSES,
        VALID_PROFS, INVALID_PROFS, VALID_ROOMS, INVALID_ROOMS);
        instance->runPassTests();
        instance->runFailTests();
        delete instance;
    }
    else
        cout << "Skipping input tests..." << endl;

    if(args.find("-p") != args.end())
    {
        // Run tests on ConflictPreprocessor
        instance = new TestConflictPreprocessor();
        instance->runPassTests();
        instance->runFailTests();
        delete instance;
    }
    else
        cout << "Skipping preprocessor tests..." << endl;

    if(args.find("-s") != args.end())
    {
        // Run tests on the Schedule
        instance = new TestSchedule();
        instance->runPassTests();
        instance->runFailTests();
        delete instance;
    }
    else
        cout << "Skipping schedule tests..." << endl;

    if(args.find("-r") != args.end())
    {
        // Run tests on the GreedyScheduleGenerator
        instance = new TestGreedyScheduleGenerator();
        instance->runPassTests();
        instance->runFailTests();
        delete instance;
    }
    else
        cout << "Skipping greedy schedule generator tests..." << endl;

    if(args.find("-n") != args.end())
    {
        // Run tests on the GeneticScheduleGenerator
        instance = new TestGeneticScheduleGenerator();
        instance->runPassTests();
        instance->runFailTests();
        delete instance;
    }
    else
        cout << "Skipping genetic schedule generator  tests..." << endl;

    if(args.find("-o") != args.end())
    {
        // Run tests on the ScheduleWriter
        instance = new  TestScheduleWriter();
        instance->runPassTests();
        instance->runFailTests();
        delete instance;
    }
    else
        cout << "Skipping output tests..." << endl;

    // Done
    cout << endl << "Testing complete." << endl;
    return 0;
}
