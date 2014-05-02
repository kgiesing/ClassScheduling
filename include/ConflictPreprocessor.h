#ifndef CONFLICTPREPROCESSOR_H
#define CONFLICTPREPROCESSOR_H

#include <vector>
#include "Course.h"

using std::vector;

class ConflictPreprocessor
{
    public:
        /**
         * Preprocesses the list of Course objects.
         * It does this by going through the list of Courses. For each Course,
         * it gets the Prof ID for that course. It then sets the
         * @param The vector of courses read from the input file.
         */
        static void preprocess(vector<Course>&);
};

#endif // CONFLICTPREPROCESSOR_H
