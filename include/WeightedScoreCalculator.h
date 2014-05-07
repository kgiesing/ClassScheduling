#pragma once
#ifndef WEIGHTEDSCORECALCULATOR_H
#define WEIGHTEDSCORECALCULATOR_H

#include "ScoreCalculator.h"

/**
 * An implementation of ScoreCalculator that calculates professor score by
 * weighting separate days as "heavier" than large schedule gaps within the
 * same day.
 */
class WeightedScoreCalculator : public ScoreCalculator {
public:
    WeightedScoreCalculator() { }
    double operator()(ProfInfo&);
};

#endif // WEIGHTEDSCORECALCULATOR_H
