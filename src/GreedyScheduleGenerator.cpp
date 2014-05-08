#include <vector>
#include <set>
#include <iostream>
#include "../include/GreedyScheduleGenerator.h"
#include "../include/Weekdays.h"
#include "../include/TimeBlock.h"

using namespace std;

Schedule* GreedyScheduleGenerator::getSchedule() {
	Schedule* schedule = new Schedule(_rooms);

	while (_courses.size() != 0) {
		int availableWeekday = NOT_AVAILABLE;
		TimeBlock time = START_08_00;

		// find the max capacity room
		// skip the room that has been scheduled
		bool roomLeft = false;
		Room maxRoom;
		while (time != TIMEBLOCK_SIZE) {
			bool findMaxFreeRoom = false;
			for (vector<Room>::iterator roomItr = _rooms.begin();
					roomItr != _rooms.end(); roomItr++) {
				if ((availableWeekday = getAvailableWeekday(*schedule, *roomItr,
						time)) != NOT_AVAILABLE) {
					findMaxFreeRoom = true;
					maxRoom = *roomItr;
					break;
				}
			}
			if (!findMaxFreeRoom) {
				time = (TimeBlock) (((int) time) + 1);
			} else {
				roomLeft = true;
				break;
			}
		}
		if (!roomLeft) {
			cout << "No room left!" << endl;
			break;
		}

		// if all the courses have been scheduled, return this function
		if (_courses.size() == 0)
			break;

		Course course = _courses.at(0);
		bool scheduled = false;

		// schedule the 2-period-courses
		for (int i = 0; i < 2; i++) {
			// find the weekday in current loop
			if (availableWeekday == NOT_AVAILABLE)
				break;
			Weekdays day;
			if (i == 0 && availableWeekday == AVAILABLE_MON_WED)
				day = MON;
			else if (i == 0 && availableWeekday == AVAILABLE_TUE_THU)
				day = TUES;
			else if (i == 1 && availableWeekday == AVAILABLE_MON_WED)
				day = WED;
			else if (i == 1 && availableWeekday == AVAILABLE_TUE_THU)
				day = THURS;

			if (isConflict(*schedule, day, time, course)) {
				for (int ttime_i = time + 1; ttime_i < TIMEBLOCK_SIZE; ttime_i++) {
					TimeBlock ttime = (TimeBlock) ttime_i;
					for (vector<Room>::iterator tRoomItr = _rooms.end() - 1;
							tRoomItr >= _rooms.begin(); tRoomItr--) {
						if (tRoomItr->getCapacity() >= course.getEnrolled()) {
							if (schedule->getCourse(*tRoomItr, day, time).getId() != ""
									|| isConflict(*schedule, day, ttime, course)) {
								break;
							} else {
								if (schedule->setCourse(course, *tRoomItr, day, ttime, 0)) {
									if (i == 1) {
										_courses.erase(_courses.begin());
									}
									scheduled = true;
									break;
								}
							}
						}
					}
					if (scheduled)
						break;
				}
			} else {
				if (schedule->setCourse(course, maxRoom, day, time, 0)) {
					// remove the scheduled course from _courses
					if (i == 1) {
						_courses.erase(_courses.begin());
					}
					scheduled = true;
				}
			}
		}
	}

	return schedule;

}

int GreedyScheduleGenerator::getAvailableWeekday(Schedule& schedule, Room& room,
		TimeBlock time) {
	if (schedule.getCourse(room, MON, time).getId() == ""
			&& schedule.getCourse(room, WED, time).getId() == "") {

		return AVAILABLE_MON_WED;
	}
	if (schedule.getCourse(room, TUES, time).getId() == ""
			&& schedule.getCourse(room, THURS, time).getId() == "")
		return AVAILABLE_TUE_THU;
	return NOT_AVAILABLE;
}

bool GreedyScheduleGenerator::isConflict(Schedule& schedule, Weekdays day,
		TimeBlock time, Course& course) {
	vector<Course> periodCourses = schedule.getCoursesAt(day, time);
	for (vector<Course>::iterator periodCourseItr = periodCourses.begin();
			periodCourseItr != periodCourses.end(); periodCourseItr++) {
		set<string> conflicts = periodCourseItr->getConflicts();
		if (conflicts.find(course.getId()) != conflicts.end()) {
			return true;
		}
	}
	return false;
}
