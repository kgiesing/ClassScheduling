#ifndef SCORECALCULATOR_H
#define SCORECALCULATOR_H

#include "TimeBlock.h"

// interface
/// class ScoreCalculator -
class ScoreCalculator {
  // Operations
public:
  virtual double operator() (Weekday w, TimeBlock t, const Prof& p) const = 0;
};

#endif // SCORECALCULATOR_H
