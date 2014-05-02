#pragma once
#ifndef LINEARSCORECALCULATOR_H
#define LINEARSCORECALCULATOR_H

#include "ScoreCalculator.h"

/**
 * An implementation of ScoreCalculator that calculates professor score by
 * simply measuring the gaps between different time blocks. It does not weigh
 * gaps between days as "heavier" than gaps between time blocks.
 */
class LinearScoreCalculator : public ScoreCalculator {
public:
    double operator()(ProfInfo&);
};

#endif // LINEARSCORECALCULATOR_H
