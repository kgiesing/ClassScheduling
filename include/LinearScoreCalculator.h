#ifndef LINEARSCORECALCULATOR_H
#define LINEARSCORECALCULATOR_H

#include "TimeBlock.h"
#include "ScoreCalculator.h"
#include "ProfInfo.h"

/// class LinearScoreCalculator -
class LinearScoreCalculator : public ScoreCalculator {
  // Associations
  ProfInfo unnamed_6;
  // Attributes
private:
  map<string, ProfInfo> _profInfo;
  // Operations
public:
  double operator() (Weekday w, TimeBlock t, const Prof& p) const;
};

#endif // LINEARSCORECALCULATOR_H
