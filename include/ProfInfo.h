#ifndef PROFINFO_H
#define PROFINFO_H

#include "TimeBlock.h"

/// class ProfInfo -
class ProfInfo {
  // Attributes
private:
  TimeBlock _lastTimeBlock;
  Weekday _lastWeekday;
  Prof& _prof;
  double _score;
  // Operations
public:
  ProfInfo (const Prof& p);
  Prof& getProf () const;
  double getScore () const;
  addTime (Weekday w, TimeBlock t);
};

#endif // PROFINFO_H
