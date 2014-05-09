#include "../include/TestConflictPreprocessor.h"
#include "../include/DataCreator.h"
#include "../../include/ConflictPreprocessor.h"

//* Implement as class is finished
void TestConflictPreprocessor::testPass(void)
{
    // Create a "fake" vector of courses
    Course c;
    vector<Course> courses = DataCreator::createVector(c);

    // Call the static method
    ConflictPreprocessor::preprocess(courses);
}

