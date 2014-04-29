#pragma once
#ifndef PROFINFO_H
#define PROFINFO_H

#include "Prof.h"
#include "TimeBlock.h"
#include "Weekdays.h"

/**
 * This class represents information about a Professor.
 */
class ProfInfo {
public:
    /**
     * Constructor.
     * @param Professor about which we are holding information.
     */
    ProfInfo (const Prof&, Weekdays = WEEKDAYS_SIZE, TimeBlock = TIMEBLOCK_SIZE);
    /**
     * Adds a time that the professor is teaching a course.
     * @param The weekday on which the course is taught.
     * @param The time block when the course is taught.
     */
    void addTime(Weekdays w, TimeBlock t);
    /**
     * Returns the last TimeBlock found.
     * @return The last TimeBlock found.
     */
    Weekdays getDay() const { return _lastWeekday; }
    /**
     * Returns the number of days this professor spends on campus.
     * @return The number of days this professor spends on campus.
     */
    unsigned getDaysOnCampus() const { return _daysOnCampus; }
    /**
     * Returns the professor about which we are holding information.
     * @return Professor about which we are holding information.
     */
    const Prof& getProf() const { return _prof; }
    /**
     * Returns the last TimeBlock found.
     * @return The last TimeBlock found.
     */
    TimeBlock getTimeBlock() const { return _lastTimeBlock; }
    /**
     * Returns the total number of time blocks the professor spends on campus.
     * @return The total number of time blocks the professor spends on campus.
     */
    unsigned getTotalTime() const { return _timeOnCampus; }
    /**
     * Sets the professor's current score.
     * @param The professor's current score.
     */
    void setScore(double score) { _score = score; }
private:
    /** Reference to the professor object */
    const Prof& _prof;
    /** The last weekday found */
    Weekdays _lastWeekday;
    /** The last time block found */
    TimeBlock _lastTimeBlock;
    /** Total number of time blocks on campus */
    unsigned _timeOnCampus;
    /** Total number of weekdays on campus */
    unsigned _daysOnCampus;
};

#endif // PROFINFO_H
