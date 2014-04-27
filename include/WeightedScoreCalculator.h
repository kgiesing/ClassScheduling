#pragma once
#ifndef WEIGHTEDSCORECALCULATOR_H
#define WEIGHTEDSCORECALCULATOR_H

#include "TimeBlock.h"
#include "ScoreCalculator.h"
#include "ProfInfo.h"
#include "Weekdays.h"
#include <map>
#include <string>
using namespace std;
/**
 * An implementation of ScoreCalculator that calculates professor scored by
 * weighting separate days as "heavier" than large schedule gaps within the
 * same day.
 */
class WeightedScoreCalculator : public ScoreCalculator {
public:
    double operator()(Weekdays w, TimeBlock t, const Prof& p) const;
private:
    map<string, ProfInfo> _profInfo; /**< Map of ID's to ProfInfo objects */
};

#endif // WEIGHTEDSCORECALCULATOR_H
