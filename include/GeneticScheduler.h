#ifndef GENETICSCHEDULER_H
#define GENETICSCHEDULER_H

#include "Scheduler.h"
#include "ScoreCalculator.h"

/// class GeneticScheduler - Takes an already-existing, valid schedule, and optimizes it using a genetic alg
class GeneticScheduler : public Scheduler {
  // Associations
  ScoreCalculator unnamed_4;
  // Attributes
private:
  ScoreCalculator& _sc;
  map<string, double> _scores;
  // Operations
public:
  getSchedule ();
private:
  optimize ();
};

#endif // GENETICSCHEDULER_H
