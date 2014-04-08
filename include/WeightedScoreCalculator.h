#ifndef WEIGHTEDSCORECALCULATOR_H
#define WEIGHTEDSCORECALCULATOR_H

#include "TimeBlock.h"
#include "ScoreCalculator.h"
#include "ProfInfo.h"

/// class WeightedScoreCalculator -
class WeightedScoreCalculator : public ScoreCalculator {
  // Associations
  ProfInfo unnamed_7;
  // Attributes
private:
  map<string, ProfInfo> _profInfo;
  // Operations
public:
  double operator() (Weekday w, TimeBlock t, const Prof& p) const;
};

#endif // WEIGHTEDSCORECALCULATOR_H
