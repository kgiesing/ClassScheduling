#include "../include/LinearScoreCalculator.h"

double LinearScoreCalculator::operator()(ProfInfo& pi)
{
    pi.setScore(pi.getTotalTime());
    return pi.getScore();
}
