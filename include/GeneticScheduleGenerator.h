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
  Schedule* _schedule;
private:
	double calculateScore(map < string, Prof >, Schedule*);
  void optimize ();
  std::map<string, ProfInfo> profInfoMap;
  ScoreCalculator& _sc;
  map<string, double> _scores;
  
  
};

#endif // GENETICSCHEDULEGENERATOR_H
