#include <vector>
#include "../include/GreedyScheduleGenerator.h"
#include "../include/Weekdays.h"
#include "../include/TimeBlock.h"

using namespace std;
Schedule* GreedyScheduleGenerator::getSchedule() {
	Schedule* schedule = new Schedule(_rooms);
	Weekdays day = 0;
	TimeBlock time = 0;

	vector<Room>::iterator roomItr;
	for (roomItr = _rooms.begin(); roomItr != _rooms.end(); roomItr++) {
		// skip the room that has been scheduled
		if (schedule->getCourse(*roomItr, day, time))
			continue;
//		if (isRoomFree(*schedule, *roomItr, time))
//			continue;

		// if all the courses have been scheduled, return this function
		if (_courses.size() == 0)
			break;

		Course course = _courses.at(0);
		bool scheduled = false;

		// look for the conflicting courses
		bool conflict = false;
		vector<Course> periodCourses = schedule->getCoursesAt(day, time);
		vector<Course>::iterator periodCourseItr;
		for (periodCourses = periodCourses.begin();
				periodCourseItr != periodCourses.end(); periodCourseItr++) {
			vector<string> conflicts = periodCourseItr->getConflicts();
			vector<string>::iterator conflictItr;
			bool exist = false;
			for (conflictItr = conflicts.begin();
					conflictItr != conflicts.end(); conflictItr++) {
				if (conflictItr->compare(course.getId())) {
					exist = true;
					break;
				}
			}
			if (exist) {
				conflict = true;
				break;
			}
		}

		if (conflict) {
			for (Weekdays tday = day; tday < WEEKDAYS_SIZE; tday++) {
				for (TimeBlock ttime = time + 1; ttime < TIMEBLOCK_SIZE;
						ttime++) {
					vector<Room>::iterator tRoomItr;
					for (tRoomItr = _rooms.end() - 1; roomItr >= _rooms.begin();
							tRoomItr--) {
						if (tRoomItr->getCapacity() >= course.getEnrolled()) {
							if (schedule->getCourse(*roomItr, day, time) != NULL) {
								break;
							} else {
								if (schedule->setCourse(course, *tRoomItr, tday, ttime, 0)) {
									_courses.erase(_courses.begin());
									scheduled = true;
									break;
								}
							}
						}
					}
					if (scheduled)
						break;
				}
				if (scheduled)
					break;
			}
		} else {
			if (schedule->setCourse(course, *roomItr, day, time, 0)) {
				// remove the scheduled course from _courses
				_courses.erase(_courses.begin());
				scheduled = true;
				break;
			}
		}
	}
	
	// calculate the score
	vector<Prof>::iterator profItr;
	for (profItr = _profs.begin(); profItr != _profs.end(); profItr++) {
		_scores.insert(pair<string, double>(profItr->getId(), _sc.operate(*profItr)));
	}
	return schedule;

}

bool isRoomFree(Schedule schedule, Room room, TimeBlock time) {
	if (schedule.getCourse(room, MON, time) == NULL && schedule.getCourse(room, WED, time) == NULL)
		return true;
	if (schedule.getCourse(room, TUES, time) == NULL && schedule.getCourse(room, THURS, time) == NULL)
		return true;
	return false;
}

bool scheduleCourse() {
	return false;
}
