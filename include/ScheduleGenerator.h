#pragma once
#ifndef SCHEDULEGENERATOR_H
#define SCHEDULEGENERATOR_H

#include "Schedule.h"

using namespace std;
/**
 * This is an abstract base class used by the various algorithms to generate
 * Schedule objects.
 */
class ScheduleGenerator {
public:
	ScheduleGenerator(vector<Room>& rooms, vector<Prof>& profs, vector<Course>& courses):
		_rooms(rooms), _courses(courses), _profs(profs), _timeout(10000){};
    /**
     * Gets the Schedule object. Subclasses will use different algorithms to
     * generate an optimized schedule.
     * @return An optimal (or near-optimal) schedule.
     */
    virtual Schedule* getSchedule() = 0;
    /**
     * Returns the timeout (last millisecond that this object should still
     * be working to generate the optimal schedule).
     * @return The timeout.
     */
    long getTimeout() { return _timeout; }
protected:
    std::vector<Room>& _rooms;     /**< Vector of Room objects */
    std::vector<Course>& _courses; /**< Vector of Course objects */
    std::vector<Prof>& _profs;     /**< Vector of Prof objects */
private:
    long _timeout;
};

#endif // SCHEDULEGENERATOR_H
