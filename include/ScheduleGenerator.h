#pragma once
#ifndef SCHEDULEGENERATOR_H
#define SCHEDULEGENERATOR_H

#include "Schedule.h"

using std::vector;

/**
 * This is an abstract base class used by the various algorithms to generate
 * Schedule objects.
 */
class ScheduleGenerator {
public:
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
    /**
     * Constructor for the abstract ScheduleGenerator base class. Subclasses
     * should construct the vectors themselves, if necessary, either by
     * accepting them as constructor arguments, or from a Schedule.
     *
     * @param timeout The initial time when the program was started.
     */
    ScheduleGenerator(long timeout) : _timeout(timeout) { }
    vector<Room>& _rooms;     /**< Vector of Room objects */
    vector<Course>& _courses; /**< Vector of Course objects */
    vector<Prof>& _profs;     /**< Vector of Prof objects */
private:
    long _timeout;            /**< Time when program was started */
};

#endif // SCHEDULEGENERATOR_H
