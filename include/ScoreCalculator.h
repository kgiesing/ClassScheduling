#pragma once
#ifndef SCORECALCULATOR_H
#define SCORECALCULATOR_H

#include "ProfInfo.h"

/**
 * Abstract base class (interface) for functor objects that calculate the
 * score for a professor.
 */
class ScoreCalculator {
public:

    /**
     * @brief Calculates the score for a professor.
     * The function operator will be passed a reference to a ProfInfo object.
     * Upon return, the ProfInfo object will be updated with the score for
     * the Prof it represents. As a matter of convenience, the score is also
     * returned from the function.
     * @param ProfInfo reference.
     * @return The professor's score.
     *
     */
    virtual double operator()(ProfInfo&) = 0;
};

#endif // SCORECALCULATOR_H
