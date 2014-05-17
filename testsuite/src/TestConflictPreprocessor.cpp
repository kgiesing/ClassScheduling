#include "../include/TestConflictPreprocessor.h"
#include "../include/DataCreator.h"
#include "../include/VectorPrinter.h"
#include "../../include/ConflictPreprocessor.h"

//* Implement as class is finished
void TestConflictPreprocessor::testPass(void)
{
    // Create a "fake" vector of courses
    Course c;
    vector<Course> courses = DataCreator::createVector(c);

    // Output values before preprocessing
    cout << "\nVector before preprocessing: " << endl;
    VectorPrinter::print(courses);

    // Call the static method
    ConflictPreprocessor::preprocess(courses);
    cout << "ConflictPreprocessor::preprocess() successfully run." << endl;

    // Output values before preprocessing
    cout << "Vector after preprocessing: " << endl;
    VectorPrinter::print(courses);
}

void TestConflictPreprocessor::testStress(unsigned seconds)
{
    // Declare variables
    Schedule instance;
    time_t future;
    unsigned long iterations;

    // Create object
    cout << "Creating object and test data..." << endl;
    vector<Course> courses = DataCreator::createVector(DataCreator::createCourse());

    // Stress test preprocess()
    cout << "Stress testing preprocess(courses)..." << endl;
    iterations = 0;
    future = time(NULL) + seconds;
    while (time(NULL) < future)
    {
        ConflictPreprocessor::preprocess(courses);
        iterations++;
    }
    cout << "\t" << iterations << " iterations in "
         << seconds << " seconds" << endl;
}
