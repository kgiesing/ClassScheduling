#include "../include/LinearScoreCalculator.h"

double LinearScoreCalculator::operator()(Weekdays w, TimeBlock t,
        const Prof& p)
{
    ProfInfo* pi = this->find(p, w, t);
    // Add the time
    pi->addTime(w, t);
    // Score is just total time, cast to double
    return static_cast<double>(pi->getTotalTime());
}
