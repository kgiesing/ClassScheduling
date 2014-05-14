#pragma once
#ifndef GREEDYSCHEDULEGENERATOR_H
#define GREEDYSCHEDULEGENERATOR_H

#include "ScheduleGenerator.h"
#include <map>
#include <string>

using std::map;
using std::string;

class GreedyScheduleGenerator : public ScheduleGenerator {
public:
	GreedyScheduleGenerator(vector<Room>&, vector<Prof>&, vector<Course>&, long);
	Schedule* getSchedule(void);
private:
    // Private member variables:
    std::vector<Room>& _rooms;
    std::vector<Prof>& _profs;
    std::vector<Course>& _courses;
    vector<bool> _isScheduled;
    vector<bool> _isFull;
    map<string, unsigned> _courseMap;
    const static Weekdays LAST_DAY = TUES;
    Schedule* _schedule;
    // Private member functions:
    bool findNextTime(const Room, Weekdays&, TimeBlock&);
    void scheduleConflict(unsigned, TimeBlock);
};

#endif // GREEDYSCHEDULEGENERATOR_H
