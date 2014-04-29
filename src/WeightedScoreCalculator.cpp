#include "../include/WeightedScoreCalculator.h"

double WeightedScoreCalculator::operator() (Weekdays w, TimeBlock t,
        const Prof& p)
{
    ProfInfo* pi = this->find(p, w, t);
    // Update ProfInfo
    pi->addTime(w, t);
    // Return score using Dzmitry's formula
    return 0.0; // TODO

}

