#include "../include/ConflictPreprocessor.h"

void ConflictPreprocessor::preprocess(vector<Course>& courses)
{
    // Optimization: Skip courses whose conflicts we have already processed
    vector< vector<bool> > checked(courses.size(), vector<bool>(courses.size()));
    for (unsigned i = 0; i < courses.size(); i++)
    {
        for (unsigned j = 0; j < courses.size(); j++)
        {
            // If we have already checked this course previously, skip it
            if (checked[i][j])
                continue;
            // A course should not conflict with itself
            if (i == j)
                continue;

            // Are the conflicts reciprocal?
            set<string> ci = courses[i].getConflicts();
            set<string> cj = courses[j].getConflicts();
            if (ci.find(courses[j].getId()) != ci.end()
                || cj.find(courses[i].getId()) != cj.end())
            {
                // Add to conflicts, for both courses
                courses[i].getConflicts().insert(courses[j].getId());
                courses[j].getConflicts().insert(courses[i].getId());
            }
            // Are they taught by the same professor?
            if (courses[j].getProfId() == courses[i].getProfId())
            {
                // Add to conflicts, for both courses
                courses[i].getConflicts().insert(courses[j].getId());
                courses[j].getConflicts().insert(courses[i].getId());
            }
            // Signify that we have checked the courses
            checked[i][j] = true;
            checked[j][i] = true;
        }
    }
}

