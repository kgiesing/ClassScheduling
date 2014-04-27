#include "../include/LinearScoreCalculator.h"

double LinearScoreCalculator::operator()(Weekdays w, TimeBlock t,
        const Prof& p)
{
    ProfInfo* pi = this->find(p, w, t);
    // calculate score
    double lastTime = static_cast<double>(pi->getTime());
    double thisTime = static_cast<double>(t);
    double score = pi->getScore();
    if (lastTime > thisTime)
        score += lastTime - thisTime;
    else
        score += thisTime - lastTime;
    pi->setScore(score);
    pi->addTime(w, t);
    return score;
}
