#pragma once
#ifndef GENETICSCHEDULEGENERATOR_H
#define GENETICSCHEDULEGENERATOR_H

#include "ScheduleGenerator.h"
#include "ScoreCalculator.h"
#include "Schedule.h"
#include <map>
#include <string>
using namespace std;

class GeneticScheduleGenerator : public ScheduleGenerator {
public:
  GeneticScheduleGenerator(ScoreCalculator&, Schedule*, long);
  Schedule* getSchedule(void);
private:
  void optimize ();
  ScoreCalculator& _sc;
  map<string, double> _scores;
  Schedule* _schedule;
};

#endif // GENETICSCHEDULEGENERATOR_H
