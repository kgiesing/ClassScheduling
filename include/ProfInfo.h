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
    ProfInfo (const Prof& p);
    /**
     * Returns the professor about which we are holding information.
     * @return Professor about which we are holding information.
     */
    const Prof& getProf() const { return _prof; }
    /**
     * Returns the professor's current score.
     * @return The professor's current score.
     */
    double getScore() const { return _score; }
    /**
     * Adds a time that the professor is teaching a course.
     * @param The weekday on which the course is taught.
     * @param The time block when the course is taught.
     */
    addTime(Weekdays w, TimeBlock t);
private:
    TimeBlock _lastTimeBlock;
    Weekdays _lastWeekday;
    Prof& _prof;
    double _score;
};

#endif // PROFINFO_H
