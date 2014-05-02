#include "../include/WeightedScoreCalculator.h"
#include <cmath> // for pow()

double WeightedScoreCalculator::operator() (ProfInfo& pi)
{
    // Calculate score using Dzmitry's formula:
    // totalTimeOnCampus * 3^numberOfDaysOnCampus / numberOfClasses
    double score = pi.getTotalTime() * pow(3.0, pi.getDaysOnCampus())
            / pi.getNumCourses();
    pi.setScore(score);
    return score;
}
