#include "../include/WeightedScoreCalculator.h"
#include <cmath> // for pow()

double WeightedScoreCalculator::operator() (Weekdays w, TimeBlock t,
        const Prof& p)
{
    ProfInfo* pi = this->find(p, w, t);
    // Update ProfInfo
    pi->addTime(w, t);
    // Return score using Dzmitry's formula:
    // totalTimeOnCampus * 3^numberOfDaysOnCampus / numberOfClasses
    return pi->getTotalTime() * pow(3.0, pi->getDaysOnCampus())
            / pi->getNumCourses();
}
