#pragma once
#ifndef SCORECALCULATOR_H
#define SCORECALCULATOR_H

#include <map>
#include <string>
#include "Prof.h"
#include "ProfInfo.h"
#include "TimeBlock.h"
#include "Weekdays.h"

using std::map;
using std::string;

/**
 * Abstract base class (interface) for functor objects that calculate the
 * score for a professor.
 */
class ScoreCalculator {
public:
    virtual double operator()(Weekdays w, TimeBlock t, const Prof& p) = 0;
    /** Destructor */
    virtual ~ScoreCalculator(void);
protected:
    /**
     * This method will find the ProfInfo associated with the Prof object
     * passed to it. If the ProfInfo object does not exist in the map, a new
     * object will be created, with the Weekdays and TimeBlock enum values
     * passed to the method.
     * @param p const Prof& Prof object to find in the map
     * @param w Weekdays If no Prof in map, creates one using this value.
     *          If Prof object is already in map, this value is ignored.
     * @param t TimeBlock If no Prof in map, creates one using this value.
     *          If Prof object is already in map, this value is ignored.
     * @return ProfInfo* Pointer to ProfInfo object (new or existing)
     */
    ProfInfo* find(const Prof&, Weekdays, TimeBlock);
private:
    /** Map of ID's to pointers to ProfInfo objects */
    map<string, ProfInfo*> _profInfo;
    /** Private copy constructor */
    ScoreCalculator(const ScoreCalculator&);
    /** Private assignment operator */
    const ScoreCalculator& operator=(const ScoreCalculator&);
};

#endif // SCORECALCULATOR_H
