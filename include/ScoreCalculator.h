#pragma once
#ifndef SCORECALCULATOR_H
#define SCORECALCULATOR_H

#include "Prof.h"
#include "TimeBlock.h"
#include "Weekdays.h"

/**
 * Abstract base class (interface) for functor objects that calculate the
 * score for a professor.
 */
class ScoreCalculator {
public:
    virtual double operator()(Weekdays w, TimeBlock t, const Prof& p) const = 0;
};

#endif // SCORECALCULATOR_H
