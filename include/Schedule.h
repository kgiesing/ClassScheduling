#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Course.h"
#include "Prof.h"
#include "Room.h"
#include "TimeBlock.h"
#include "Weekdays.h"

/**
 * This class represents a schedule for all courses.
 */
class Schedule {
    // TODO What type of objects will these methods return?
public:
    getScheduleFor(const Course& course) const;
    getScheduleFor(const Prof& prof) const;
    getScheduleFor(const Room& room) const;
    getScheduleFor(TimeBlock time) const;
private:
    std::map<Room, std::vector<Course> > _schedule;
};

#endif // SCHEDULE_H
