#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Course.h"
#include "Prof.h"
#include "Room.h"
#include "TimeBlock.h"
#include "Weekdays.h"
#include <map>
#include <vector>
/**
 * This class represents a schedule for all courses.
 */
class Schedule {
    // TODO What type of objects will these methods return?
public:
	Schedule(std::vector < Room > );
	std::map < Room, std::vector < std::vector < Course > > > getSchedule();
	bool setCourse(const Course&, const Room&, Weekdays, TimeBlock, int);
	Course getCourse(const Room&, Weekdays, TimeBlock);
	std::vector < Course > getCoursesAt(Weekdays, TimeBlock);
	std::vector < Weekdays > getWeekdaysFor(const Course&);
	TimeBlock getTimeFor(const Course&);
	Room getRoomFor(const Course&);
    //getScheduleFor(const Course& course) const;
    //getScheduleFor(const Prof& prof) const;
    //getScheduleFor(const Room& room) const;
    //getScheduleFor(TimeBlock time) const;
private:
	std::map < Room, std::vector < std::vector < Course > > > _schedule;
    //std::map<Room, std::vector<Course> > _schedule;
};

#endif // SCHEDULE_H
