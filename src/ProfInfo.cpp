#include "../include/ProfInfo.h"

ProfInfo::ProfInfo(const Prof& p, Weekdays w, TimeBlock t) :
    _prof(p), _lastWeekday(w), _lastTimeBlock(t), _timeOnCampus(0),
    _daysOnCampus(0), _courses(0)
    { }

void ProfInfo::addTime(Weekdays w, TimeBlock t)
{
    if (_lastWeekday < w)
    {
        // New weekday; add 1 day, and 1 time block
        _daysOnCampus++;
        _timeOnCampus++;
    }
    else
    {
        // Same weekday; add difference of time blocks
        unsigned lastTime = static_cast<unsigned>(_lastTimeBlock);
        unsigned thisTime = static_cast<unsigned>(t);
        _timeOnCampus = (lastTime < thisTime) ?
            thisTime - lastTime : lastTime - thisTime;
    }
    _lastTimeBlock = t;
    _lastWeekday = w;
    _courses++;
}

