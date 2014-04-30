#include "../include/ProfInfo.h"
#include <algorithm> // for std::count

ProfInfo::ProfInfo(const Prof& p) : _prof(p), _courses(0)
{
    _timeBlocks.resize(WEEKDAYS_SIZE);
    _isOnCampus.resize(WEEKDAYS_SIZE);
}

void ProfInfo::addTime(Weekdays w, TimeBlock t)
{
    unsigned day = static_cast<unsigned>(w);
    if (_isOnCampus[day])
    {
        // Set first or last if applicable
        if (_timeBlocks[day].first > t)
            _timeBlocks[day].first = t;
        if (_timeBlocks[day].second < t)
            _timeBlocks[day].second = t;
    }
    else
    {
        // New day
        _isOnCampus[day] = 1;
        _timeBlocks[day] = std::make_pair(t, t);
    }
    _courses++;
}

unsigned ProfInfo::getDaysOnCampus() const
{
    return std::count(_isOnCampus.begin(), _isOnCampus.end(), 0);
}

unsigned ProfInfo::getTotalTime() const
{
    unsigned time(0);
    for (int i = 0; i < WEEKDAYS_SIZE; i++)
    {
        if (_isOnCampus[i])
            time += _timeBlocks[i].second - _timeBlocks[i].first;
    }
    return time;
}

