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

