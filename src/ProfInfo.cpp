#include "../include/ProfInfo.h"

ProfInfo::ProfInfo(const Prof& p, Weekdays w, TimeBlock t) :
    _prof(p), _lastWeekday(w), _lastTimeBlock(t), _score(0), _daysOnCampus(0)
    { }

void ProfInfo::addTime(Weekdays w, TimeBlock t)
{
    if (w > _lastWeekday)
        _daysOnCampus++;
    _lastTimeBlock = t;
    _lastWeekday = w;
}

