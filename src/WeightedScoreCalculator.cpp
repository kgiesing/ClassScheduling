#include "../include/WeightedScoreCalculator.h"
#include <cmath> // for pow()

double WeightedScoreCalculator::operator() (ProfInfo& pi)
{
    double score;
    // Calculate score using Dzmitry's formula:
    // totalTimeOnCampus * 3^numberOfDaysOnCampus / numberOfClasses
    if (0 == pi.getNumCourses())
        score = 0;
    else
    {
        // Necessary for MS compilers
        double d = pi.getDaysOnCampus();
        score = pi.getTotalTime() * pow(3.0, d) / pi.getNumCourses();
    }
    pi.setScore(score);
    return score;
}
