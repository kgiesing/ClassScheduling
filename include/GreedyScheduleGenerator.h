#pragma once
#ifndef GREEDYSCHEDULEGENERATOR_H
#define GREEDYSCHEDULEGENERATOR_H

#include "ScheduleGenerator.h"
#include "ScoreCalculator.h"
#include <map>
#include <string>

using namespace std;

class GreedyScheduleGenerator : public ScheduleGenerator {
public:
  Schedule* getSchedule(void);
private:
  ScoreCalculator& _sc;
  map<string, double> _scores;
};

#endif // GREEDYSCHEDULEGENERATOR_H
