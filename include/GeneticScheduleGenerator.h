#pragma once
#ifndef GENETICSCHEDULEGENERATOR_H
#define GENETICSCHEDULEGENERATOR_H

#include "ScheduleGenerator.h"
#include "ScoreCalculator.h"
#include "Schedule.h"
#include <map>
#include <string>
using namespace std;

class GeneticScheduleGenerator : public ScheduleGenerator
{
public:
    GeneticScheduleGenerator(ScoreCalculator&, Schedule*, long);
    Schedule * getSchedule(void);
private:
    // Private member veriables
    ScoreCalculator& _sc;
    Schedule* _schedule;
    Schedule* _mutation;
    static const Weekdays END_OF_WEEK = WED;
    // Private methods
    void calculateScore(Schedule*);
    // Make this object singular
    GeneticScheduleGenerator(GeneticScheduleGenerator&);
    GeneticScheduleGenerator& operator=(const GeneticScheduleGenerator&);
};

#endif // GENETICSCHEDULEGENERATOR_H
