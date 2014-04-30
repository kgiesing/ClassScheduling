#pragma once
#ifndef PROFINFO_H
#define PROFINFO_H

#include "Prof.h"
#include "TimeBlock.h"
#include "Weekdays.h"
#include <vector>
#include <utility>

using std::vector;
using std::pair;

/**
 * This class represents information about a Professor.
 */
class ProfInfo {
public:
    /**
     * Constructor.
     * @param Professor about which we are holding information.
     * @param Weekday for the time we are calculating.
     * @param TimeBlock for the time we are calculating.
     */
    ProfInfo (const Prof&);
    /**
     * Adds a time when the professor is teaching a course.
     * @param The weekday on which the course is taught.
     * @param The time block when the course is taught.
     */
    void addTime(Weekdays w, TimeBlock t);
    /**
     * Returns the number of days this professor spends on campus.
     * @return The number of days this professor spends on campus.
     */
    unsigned getDaysOnCampus() const;
    /**
     * Returns the number of courses this professor teaches.
     * @return Number of courses this professor teaches.
     */
    unsigned getNumCourses() const { return _courses; }
    /**
     * Returns the professor about which we are holding information.
     * @return Professor about which we are holding information.
     */
    const Prof& getProf() const { return _prof; }
    /**
     * Returns the total number of time blocks the professor spends on campus.
     * @return The total number of time blocks the professor spends on campus.
     */
    unsigned getTotalTime() const;
private:
    /** Read-only reference to the professor object */
    const Prof& _prof;
    /** Total number of courses taught */
    unsigned _courses;
    /** Data structure holding whether a professor spends a day on campus */
    vector<char> _isOnCampus; // Note: vector<bool> is "broken"
    /** Data structure holding the first and last TimeBlocks per Weekday */
    vector< pair<TimeBlock, TimeBlock> > _timeBlocks;
};

#endif // PROFINFO_H
