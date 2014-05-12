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
	GreedyScheduleGenerator(vector<Room>& roomV, vector<Prof>& profV, vector<Course>& courseV, long timeout) :
		ScheduleGenerator(timeout), _rooms(roomV), _profs(profV), _courses(courseV){};
private:
    std::vector<Room>& _rooms;     /**< Vector of Room objects */
    std::vector<Prof>& _profs;     /**< Vector of Prof objects */
    std::vector<Course>& _courses; /**< Vector of Course objects */

	static const int AVAILABLE_MON_WED = 1;
	static const int AVAILABLE_TUE_THU = 2;
	static const int NOT_AVAILABLE = 0;
	int getAvailableWeekday(Schedule& schedule, Room& room, TimeBlock time);
	bool isConflict(Schedule& schedule, Weekdays day, TimeBlock time, Course& course);
};

#endif // GREEDYSCHEDULEGENERATOR_H
