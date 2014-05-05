#include <vector>
#include <set>
#include "../include/GreedyScheduleGenerator.h"
#include "../include/Weekdays.h"
#include "../include/TimeBlock.h"

using namespace std;
Schedule* GreedyScheduleGenerator::getSchedule() {
	Schedule* schedule = new Schedule(_rooms);
	Weekdays day = MON;
	TimeBlock time = START_08_00;

	vector<Room>::iterator roomItr;
	for (roomItr = _rooms.begin(); roomItr != _rooms.end(); roomItr++) {
		// skip the room that has been scheduled
		if (schedule->getCourse(*roomItr, day, time).getId() != "")
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
		for (periodCourseItr = periodCourses.begin();
				periodCourseItr != periodCourses.end(); periodCourseItr++) {
			set<string> conflicts = periodCourseItr->getConflicts();
			if (conflicts.find(course.getId()) != conflicts.end()) {
				conflict = true;
				break;
			}
		}

		if (conflict) {
			for (int tday_i = day; tday_i < WEEKDAYS_SIZE; tday_i++) {
				for (int ttime_i = time + 1; ttime_i < TIMEBLOCK_SIZE;
						ttime_i++) {
					vector<Room>::iterator tRoomItr;
					Weekdays tday = static_cast<Weekdays>(tday_i);
					TimeBlock ttime = static_cast<TimeBlock>(ttime_i);
					for (tRoomItr = _rooms.end() - 1; roomItr >= _rooms.begin();
							tRoomItr--) {
						if (tRoomItr->getCapacity() >= course.getEnrolled()) {
							if (schedule->getCourse(*roomItr, day, time).getId() != "") {
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
		_scores.insert(pair<string, double>(profItr->getId(), _sc(*profItr)));
	}
	return schedule;

}

bool isRoomFree(Schedule schedule, Room room, TimeBlock time) {
	if (schedule.getCourse(room, MON, time).getId() != "" && schedule.getCourse(room, WED, time).getId() != "")
		return true;
	if (schedule.getCourse(room, TUES, time).getId() != "" && schedule.getCourse(room, THURS, time).getId() != "")
		return true;
	return false;
}

bool scheduleCourse() {
	return false;
}
