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
	GreedyScheduleGenerator(vector<Room>& roomV, vector<Prof>& profV, vector<Course>& courseV, long timeout) :
		ScheduleGenerator(timeout), _rooms(roomV), _profs(profV), _courses(courseV) { };
	Schedule* getSchedule(void);
private:
    std::vector<Room>& _rooms;     /**< Vector of Room objects */
    std::vector<Prof>& _profs;     /**< Vector of Prof objects */
    std::vector<Course>& _courses; /**< Vector of Course objects */
};

#endif // GREEDYSCHEDULEGENERATOR_H
