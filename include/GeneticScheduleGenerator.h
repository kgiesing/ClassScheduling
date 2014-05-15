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
    ~GeneticScheduleGenerator(void);
    Schedule * getSchedule(void);
private:
    // Private member veriables
    ScoreCalculator& _sc;
    Schedule* _schedule;
    Schedule* _mutation;
    map<string, ProfInfo*>* _info; /**< professor ID to ProfInfo */
    map<string, ProfInfo*>* _mnfo; /**< mutation's version of _info */
    static const Weekdays END_OF_WEEK = WED;
    // Private methods
    void calculateScore(Schedule*, map<string, ProfInfo*>&);
    // Make this object singular
    GeneticScheduleGenerator(GeneticScheduleGenerator&);
    GeneticScheduleGenerator& operator=(const GeneticScheduleGenerator&);
};

#endif // GENETICSCHEDULEGENERATOR_H
