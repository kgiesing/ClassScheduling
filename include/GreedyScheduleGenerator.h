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
	GreedyScheduleGenerator(vector<Room>& roomV, vector<Prof>& profV, vector<Course>& courseV, ScoreCalculator& sc);
private:
	ScoreCalculator& _sc;
	map<string, double> _scores;

	static const int AVAILABLE_MON_WED = 1;
	static const int AVAILABLE_TUE_THU = 2;
	static const int NOT_AVAILABLE = 0;
	int getAvailableWeekday(Schedule& schedule, Room& room, TimeBlock time);
};

#endif // GREEDYSCHEDULEGENERATOR_H
