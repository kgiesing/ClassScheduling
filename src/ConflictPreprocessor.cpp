#include "ConflictPreprocessor.h"

void ConflictPreprocessor::preprocess(vector<Course>& courses)
{
    for (unsigned i = 0; i < courses.size(); i++)
    {
        for (unsigned j = 0; j < courses.size(); j++)
        {
            // Are they taught by the same professor?
            if (courses[j].getProfId() == courses[i].getProfId())
            {
                // Add to conflicts, for both courses
                courses[i].getConflicts().insert(courses[j].getId());
                courses[j].getConflicts().insert(courses[i].getId());
            }
        }
    }
}

