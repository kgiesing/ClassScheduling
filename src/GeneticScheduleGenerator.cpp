#include "../include/GeneticScheduleGenerator.h"
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include "../include/Weekdays.h"
#include "../include/TimeBlock.h"
#include <iostream>
#include "../include/ScheduleCalculator.h"

GeneticScheduleGenerator::GeneticScheduleGenerator(ScoreCalculator& sc, Schedule* schedule, long timeout )
	: ScheduleGenerator(timeout) , _sc(sc) {
		_schedule = schedule;
}


Schedule* GeneticScheduleGenerator::getSchedule(){
	Schedule* bestSchedule = new Schedule(*_schedule);
	// delete _schedule;
	map<string, Prof> professors = bestSchedule->getProfs();

	bestSchedule->setScore(ScheduleCalculator::calculateScore(bestSchedule, _sc));

	srand(time(NULL));
	vector<Room> rooms = bestSchedule->getRooms();
	int numberOfRooms = rooms.size();
	Room room1, room2;
	Weekdays day1, day2;
	TimeBlock time1, time2;
	long endTime = getTimeout();
	do{
		Schedule* _changedSchedule = new Schedule(*bestSchedule);
		room1 = rooms.at(rand() % numberOfRooms);
		room2 = rooms.at(rand() % numberOfRooms);
		day1 = (Weekdays)(rand() % WED);
		day2 = (Weekdays)(rand() % WED);
		time1 = (TimeBlock)(rand() % TIMEBLOCK_SIZE);
		time2 = (TimeBlock)(rand() % TIMEBLOCK_SIZE);
		if (_changedSchedule->getCourse(room1, day1, time1).getEnrolled() > room2.getCapacity() ||
			_changedSchedule->getCourse(room2, day2, time2).getEnrolled() > room1.getCapacity() ||
			_changedSchedule->getCourse(room2, day2, time2) == _changedSchedule->getCourse(room1, day1, time1))
		{
			delete _changedSchedule;
			continue;
		}
		else
		{

			if (_changedSchedule->swapCourses(room1, day1, time1, room2, day2, time2)){

				Course course1 = _changedSchedule->getCourse(room1, day1, time1);
				Course course2 = _changedSchedule->getCourse(room2, day2, time2);
				vector<Course> classesTaughtWithCourse1 = _changedSchedule->getCoursesAt(day1, time1);
				vector<Course> classesTaughtWithCourse2 = _changedSchedule->getCoursesAt(day2, time2);

				set<string> conflictsCourse1 = course1.getConflicts();
				set<string> conflictsCourse2 = course2.getConflicts();
				bool isConflicting = false;
				for (unsigned i = 0; i < classesTaughtWithCourse1.size(); i++){
					if (conflictsCourse1.find(classesTaughtWithCourse1.at(i).getId()) != conflictsCourse1.end()){
						isConflicting = true;
						break;
					}
				}
				if (!isConflicting){
					for (unsigned i = 0; i < classesTaughtWithCourse2.size(); i++){
						if (conflictsCourse2.find(classesTaughtWithCourse2.at(i).getId()) != conflictsCourse2.end()){
							isConflicting = true;
							break;
						}
					}
				}
				if (isConflicting){
					delete _changedSchedule;
				}
				else{
					double newScore = ScheduleCalculator::calculateScore(_changedSchedule, _sc);
					if (bestSchedule->getScore() > newScore){
						delete bestSchedule;
						bestSchedule = _changedSchedule;
						bestSchedule->setScore(newScore);
					}
					else{
						delete _changedSchedule;
					}
				}
			}
		}
	} while (time(0) < endTime);
	return bestSchedule;
}
