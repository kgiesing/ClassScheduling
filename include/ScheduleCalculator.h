#ifndef SCHEDULECALCULATOR_H
#define SCHEDULECALCULATOR_H

#include "Schedule.h"
#include "ScoreCalculator.h"

class ScheduleCalculator
{
public:

    /**
     * Calculates the score for an entire Schedule.
     * The score will be saved into the Schedule object, and also returned
     * from the function, simply as a convenience.
     * @param Pointer to Schedule object.
     * @param ScoreCalculator to use to calculate each professor's score.
     * @return The calculated score.
     *
     */
    static double calculateScore(Schedule*, ScoreCalculator&);
    /** Dzmitry's version. */
    static double calculateScore(Schedule*, ScoreCalculator&, map<string, Prof>);
private:
    /** Private constructor. */
    ScheduleCalculator() { }
};

#endif // SCHEDULECALCULATOR_H
