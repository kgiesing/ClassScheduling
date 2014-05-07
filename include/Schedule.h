#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Course.h"
#include "Prof.h"
#include "Room.h"
#include "TimeBlock.h"
#include "Weekdays.h"
#include "ScoreCalculator.h"
#include <map>
#include <vector>
/**
 * This class represents a schedule for all courses.
 */
class Schedule {
public:
	Schedule(std::vector < Room >, std::vector < Prof > );
	std::map < Room, std::vector < std::vector < Course > > > getSchedule();
	bool setCourse(const Course&, const Room&, Weekdays, TimeBlock, int);
	Course getCourse(const Room&, Weekdays, TimeBlock);
	std::vector < Course > getCoursesAt(Weekdays, TimeBlock);
	std::vector < Weekdays > getWeekdaysFor(const Course&);
	TimeBlock getTimeFor(const Course&);
	Room getRoomFor(const Course&);
	void swapCourses(Room, Weekdays, TimeBlock, Room, Weekdays, TimeBlock);
	void setScore (double score){ _score = score; }
	double getScore() { return _score; }
	Prof getProf(string);
	Prof getProf(Course);
private:
	std::map < Room, std::vector < std::vector < Course > > > _schedule;
	std::map < std::string, Prof > _professors;
	double _score;
};

#endif // SCHEDULE_H
