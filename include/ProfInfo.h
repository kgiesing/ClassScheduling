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
     */
    ProfInfo (const Prof& prof) : _prof(prof), _courses(0), _daysOnCampus(0),
            _timeBlocks(0), _score(0.0) { }
    /**
     * Returns the number of days this professor spends on campus.
     * @return The number of days this professor spends on campus.
     */
    unsigned getDaysOnCampus() const { return _daysOnCampus; }
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
     * @brief Returns the professor's score.
     * The score should be calculated using one of the subclasses of the
     * ScoreCalculator base class (a functor).
     * @return The total number of time blocks the professor spends on campus.
     */
    double getScore() const {return _score; }
    /**
     * Returns the total number of time blocks the professor spends on campus.
     * @return The total number of time blocks the professor spends on campus.
     */
    unsigned getTotalTime() const {return _timeBlocks; }
    /**
     * Sets the number of days this professor spends on campus.
     * @param The number of days this professor spends on campus.
     */
    void setDaysOnCampus(unsigned days) { _daysOnCampus = days; }
    /**
     * Sets the number of courses this professor teaches.
     * @param Number of courses this professor teaches.
     */
    void setNumCourses(unsigned courses) { _courses = courses; }
    /**
     * @brief Sets the professor's score.
     * The score should be calculated using one of the subclasses of the
     * ScoreCalculator base class (a functor).
     * @param The total number of time blocks the professor spends on campus.
     */
    void setScore(double score) {_score = score; }
    /**
     * Sets the total number of time blocks the professor spends on campus.
     * @param The total number of time blocks the professor spends on campus.
     */
    void setTotalTime(unsigned timeBlocks) {_timeBlocks = timeBlocks; }
private:
    /** Read-only reference to the professor object */
    const Prof& _prof;
    /** Total number of courses taught */
    unsigned _courses;
    /** TOtal number of days spent on campus */
    unsigned _daysOnCampus;
    /** Total number of time blocks spent on campus */
    unsigned _timeBlocks;
    /** The professor's score */
    double _score;
};

#endif // PROFINFO_H
