#pragma once
#ifndef GENETICSCHEDULEGENERATOR_H
#define GENETICSCHEDULEGENERATOR_H

#include "ScheduleGenerator.h"
#include "ScoreCalculator.h"
#include <map>
#include <string>
using namespace std;

class GeneticScheduleGenerator : public ScheduleGenerator {
public:
  Schedule* getSchedule(void);
private:
  void optimize ();
  ScoreCalculator& _sc;
  map<string, double> _scores;
};

#endif // GENETICSCHEDULEGENERATOR_H
