#pragma once
#ifndef WEIGHTEDSCORECALCULATOR_H
#define WEIGHTEDSCORECALCULATOR_H

#include <map>
#include <string>
#include "ScoreCalculator.h"
#include "ProfInfo.h"

using std::map;
using std::string;

/**
 * An implementation of ScoreCalculator that calculates professor score by
 * weighting separate days as "heavier" than large schedule gaps within the
 * same day.
 */
class WeightedScoreCalculator : public ScoreCalculator {
public:
    double operator()(Weekdays w, TimeBlock t, const Prof& p);
private:
    map<string, ProfInfo> _profInfo; /**< Map of ID's to ProfInfo objects */
};

#endif // WEIGHTEDSCORECALCULATOR_H
