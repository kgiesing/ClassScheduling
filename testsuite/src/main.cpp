/** @file File containing the test suite's main() function. */
#include "../include/TestHeaders.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;

// Global constants: valid and invalid test filenames
const string VALID_COURSES = "./res/courses_ok.txt";
const string VALID_PROFS   = "./res/profs_ok.txt";
const string VALID_ROOMS   = "./res/rooms_ok.txt";
const string INVALID_COURSES = "./res/courses_fail.txt";
const string INVALID_PROFS   = "./res/profs_fail.txt";
const string INVALID_ROOMS   = "./res/rooms_fail.txt";

// Function signatures
void runTests(TestRunner*, bool, bool = true);

/**
 * Main method for the test suite.
 * Accepts any of the following command-line arguments, in any order.
 * Passing no arguments results in tests being run for all components.
 * - -c: run tests on a specific Class. If you use this argument, the next
 *       argument passed must be the name of the class to test. Using this
 *       argument will override any other arguments except -t.
 * - -i: run tests on the Input component (Reader classes)
 * - -n: run tests on the geNetic schedule generator
 * - -o: (lower-case "oh"): run tests on the Output component (Writer)
 * - -p: run tests on the Preprocessor component
 * - -r: run tests on the gReedy schedule generator
 * - -s: run tests on the Schedule object
 * - -t: run sTress tests. These tests will be run on any of the components
 *       that are tested. If you do not pass this argument, stress tests will
 *       not be run at all; and if you do pass this argument, no tests other
 *       than stress tests will be run.
 * (Note: the colon, ":", is not part of the argument.)
 * @param Argument count
 * @param Argument values
 * @return 0 on success; non-zero on failure
 */
int main(int argc, char* argv[])
{
    TestRunner* instance = 0;
    bool stress = false;

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
    // See if the user is running stress tests
    if (args.find("-t") != args.end())
        stress = true;
    // See if user is testing a specific class
    if (args.find("-c") != args.end())
    {
        // This would be so much easier with reflection...
        if (args.find("ConflictPreprocessor") != args.end())
            instance = new TestConflictPreprocessor();
        if (args.find("Course") != args.end())
            instance = new TestCourse();
        if (args.find("CourseReader") != args.end())
        {
            // Dynamically create invalid data
            DataCreator::createVectorFile(INVALID_COURSES,
                    DataCreator::createCourse(), 50);
            instance = new TestCourseReader(VALID_COURSES, INVALID_COURSES);
        }
        if (args.find("FileReaderFactory") != args.end())
        {
            // Dynamically create invalid data
            DataCreator::createVectorFile(INVALID_COURSES,
                    DataCreator::createCourse(), 50);
            DataCreator::createVectorFile(INVALID_PROFS,
                    DataCreator::createProf(), 10);
            DataCreator::createVectorFile(INVALID_ROOMS,
                    DataCreator::createRoom(), 5);
            instance = new TestFileReaderFactory(VALID_COURSES, INVALID_COURSES,
                    VALID_PROFS, INVALID_PROFS, VALID_ROOMS, INVALID_ROOMS);
        }
        if (args.find("GeneticScheduleGenerator") != args.end())
            instance = new TestGeneticScheduleGenerator();
        if (args.find("GreedyScheduleGenerator") != args.end())
            instance = new TestGreedyScheduleGenerator();
        if (args.find("Prof") != args.end())
            instance = new TestProf();
        if (args.find("ProfInfo") != args.end())
            instance = new TestProfInfo();
        if (args.find("ProfReader") != args.end())
        {
            // Dynamically create invalid data
            DataCreator::createVectorFile(INVALID_PROFS,
                    DataCreator::createProf());
            instance = new TestProfReader(VALID_PROFS, INVALID_PROFS);
        }
        if (args.find("Room") != args.end())
            instance = new TestRoom();
        if (args.find("RoomReader") != args.end())
        {
            // Dynamically create invalid data
            DataCreator::createVectorFile(INVALID_ROOMS,
                    DataCreator::createCourse());
            instance = new TestRoomReader(VALID_ROOMS, INVALID_ROOMS);
        }
        if (args.find("Schedule") != args.end())
            instance = new TestSchedule();
        if (args.find("ScheduleCalculator") != args.end())
            instance = new TestScheduleCalculator();
        if (args.find("ScheduleWriter") != args.end())
            instance = new TestScheduleWriter();
        if (args.find("ScoreCalculator") != args.end())
            instance = new TestScoreCalculators();
        // These are concrete subclasses; test superclass
        if (args.find("LinearScoreCalculator") != args.end())
            instance = new TestScoreCalculators();
        if (args.find("WeightedScoreCalculator") != args.end())
            instance = new TestScoreCalculators();
        // instance may still be null if the class isn't valid
        if (instance == 0)
        {
            std::cerr << "Invalid class passed on command line." << endl;
            return -1;
        }
        runTests(instance, stress, false);
        delete instance;
        return 0;
    }
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
        runTests(instance, stress);
        delete instance;
    }
    else
        cout << "Skipping input tests..." << endl;

    if(args.find("-p") != args.end())
    {
        // Run tests on ConflictPreprocessor
        instance = new TestConflictPreprocessor();
        runTests(instance, stress);
        delete instance;
    }
    else
        cout << "Skipping preprocessor tests..." << endl;

    if(args.find("-s") != args.end())
    {
        // Run tests on the Schedule
        instance = new TestSchedule();
        runTests(instance, stress);
        delete instance;
    }
    else
        cout << "Skipping schedule tests..." << endl;

    if(args.find("-r") != args.end())
    {
        // Run tests on the GreedyScheduleGenerator
        instance = new TestGreedyScheduleGenerator();
        runTests(instance, stress);
        delete instance;
    }
    else
        cout << "Skipping greedy schedule generator tests..." << endl;

    if(args.find("-n") != args.end())
    {
        // Run tests on the GeneticScheduleGenerator
        instance = new TestGeneticScheduleGenerator();
        runTests(instance, stress);
        delete instance;
    }
    else
        cout << "Skipping genetic schedule generator  tests..." << endl;

    if(args.find("-o") != args.end())
    {
        // Run tests on the ScheduleWriter
        instance = new  TestScheduleWriter();
        runTests(instance, stress);
        delete instance;
    }
    else
        cout << "Skipping output tests..." << endl;

    // Done
    cout << endl << "Testing complete." << endl;
    return 0;
}

void runTests(TestRunner* instance, bool stress, bool runPre)
{
    if(stress)
        instance->runStressTests();
    else
    {
        instance->runPassTests(runPre);
        instance->runFailTests(runPre);
    }
}
