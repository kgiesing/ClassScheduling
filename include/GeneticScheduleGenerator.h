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
	Schedule* _schedule;
	double calculateScore(Prof, Schedule*, double);
	double calculateScore(map < string, Prof >, Schedule*);
  std::map<string, ProfInfo> profInfoMap;
  ScoreCalculator& _sc;
  map<string, double> _scores;
};

#endif // GENETICSCHEDULEGENERATOR_H
