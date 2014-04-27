#include "../include/ScoreCalculator.h"

ScoreCalculator::~ScoreCalculator(void)
{
    // Delete all pointers in the map
    for(map<string, ProfInfo*>::iterator it = _profInfo.begin();
            it != _profInfo.end(); ++it)
        delete it->second;
}

ProfInfo* ScoreCalculator::find(const Prof& p, Weekdays w, TimeBlock t)
{
    ProfInfo* pi;
    if(_profInfo.find(p.getId()) == _profInfo.end())
    {
        // Create new ProfInfo, insert into map
        pi = new ProfInfo(p, w, t);
        _profInfo.insert(std::make_pair(p.getId(), pi));
    }
    else
    {
        // Retrieve the ProfInfo pointer from the map
        pi = _profInfo[p.getId()];
    }
    return pi;
}


