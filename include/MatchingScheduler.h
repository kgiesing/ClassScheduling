#ifndef MATCHINGSCHEDULER_H
#define MATCHINGSCHEDULER_H

#include "Scheduler.h"
#include "ScoreCalculator.h"

/// class MatchingScheduler - Generates the schedule by matching largest-capacity rooms to courses with the l
class MatchingScheduler : public Scheduler {
  // Associations
  ScoreCalculator unnamed_5;
  // Attributes
private:
  ScoreCalculator& _sc;
  map<string, double> _scores;
  // Operations
public:
  getSchedule ();
};

#endif // MATCHINGSCHEDULER_H
