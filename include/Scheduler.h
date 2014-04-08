#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Schedule.h"

/// class Scheduler -
class Scheduler {
  // Associations
  Schedule* unnamed_3;
  // Attributes
private:
  long _timeout;
protected:
  std::vector<Room>& _rooms;
  std::vector<Course>& _courses;
  std::vector<Prof>& _profs;
  Schedule _schedule;
  // Operations
public:
  virtual Schedule getSchedule () = 0;
  long getTimeout ();
};

#endif // SCHEDULER_H
