#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "TimeBlock.h"
#include "Weekdays.h"

/// class Schedule -
class Schedule {
  // Associations
  TimeBlock* unnamed_2;
  Weekdays* unnamed_1;
  // Attributes
private:
  std::map<Room, std::vector<Course>> _schedule;
  // Operations
public:
  getScheduleFor (const Course& course) const;
  getScheduleFor (const Prof& prof) const;
  getScheduleFor (const Room& room) const;
  getScheduleFor (TimeBlock time) const;
};

#endif // SCHEDULE_H
