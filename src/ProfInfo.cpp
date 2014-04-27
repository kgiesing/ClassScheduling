#include "../include/ProfInfo.h"

ProfInfo::ProfInfo(const Prof& p, Weekdays w, TimeBlock t) :
    _prof(p), _lastWeekday(w), _lastTimeBlock(t), _score(0) { }

void ProfInfo::addTime(Weekdays w, TimeBlock t)
{
    _lastTimeBlock = t;
    _lastWeekday = w;
}

