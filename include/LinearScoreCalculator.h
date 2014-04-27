#pragma once
#ifndef LINEARSCORECALCULATOR_H
#define LINEARSCORECALCULATOR_H

#include <map>
#include <string>
#include "ProfInfo.h"
#include "ScoreCalculator.h"

using std::map;
using std::string;

/**
 * An implementation of ScoreCalculator that calculates professor score by
 * simply measuring the gaps between different time blocks. It does not weigh
 * gaps between days as "heavier" than gaps between time blocks.
 */
class LinearScoreCalculator : public ScoreCalculator {
public:
    double operator() (Weekdays w, TimeBlock t, const Prof& p) const;
private:
    map<string, ProfInfo> _profInfo; /**< Map of ID's to ProfInfo objects */
};

#endif // LINEARSCORECALCULATOR_H
