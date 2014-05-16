#include "../include/GeneticScheduleGenerator.h"
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include "../include/Weekdays.h"
#include "../include/TimeBlock.h"
#include <iostream>

GeneticScheduleGenerator::GeneticScheduleGenerator(ScoreCalculator& sc, Schedule* schedule, long timeout )
	: ScheduleGenerator(timeout) , _sc(sc) {
		_schedule = schedule;
}

double GeneticScheduleGenerator::calculateScore(Prof prof, Schedule* schedule, double oldScoreProf){
	double score = 0;
	ProfInfo pi(prof);
	vector<Course> taughtOnMonday;
	vector<Course> taughtOnTuesday;
	vector<Course> taughtOnWednesday;
	vector<Course> taughtOnThursday;
	vector<Course> taughtOnFriday;
	vector<Course> coursesTaughtByProfessor = schedule->getCoursesTaughtBy(prof);
	pi.setNumCourses(coursesTaughtByProfessor.size());
	set <Weekdays> daysOnCampusSet;
	for (unsigned i = 0; i < coursesTaughtByProfessor.size(); i++){


		vector<Weekdays> daysForCourse = schedule->getWeekdaysFor(coursesTaughtByProfessor.at(i));

		for (unsigned j = 0; j < daysForCourse.size(); j++){
			daysOnCampusSet.insert(daysForCourse.at(j));
			switch (daysForCourse.at(j)){
			case MON:
				taughtOnMonday.push_back(coursesTaughtByProfessor.at(i));
				break;
			case TUES:
				taughtOnTuesday.push_back(coursesTaughtByProfessor.at(i));
				break;
			case WED:
				taughtOnWednesday.push_back(coursesTaughtByProfessor.at(i));
				break;
			case THURS:
				taughtOnThursday.push_back(coursesTaughtByProfessor.at(i));
				break;
			case FRI:
				taughtOnFriday.push_back(coursesTaughtByProfessor.at(i));
				break;
			}
		}
		pi.setDaysOnCampus(daysOnCampusSet.size());

	}
	int min, max, total = 0;
	if (taughtOnMonday.size() > 0){
		min = max = schedule->getTimeFor(taughtOnMonday.at(0));
		for (unsigned j = 1; j < taughtOnMonday.size(); j++){
			if (schedule->getTimeFor(taughtOnMonday.at(j)) < min){
				min = schedule->getTimeFor(taughtOnMonday.at(j));
			}
			if (schedule->getTimeFor(taughtOnMonday.at(j)) > max){
				max = schedule->getTimeFor(taughtOnMonday.at(j));
			}
		}
		total += max - min + 1;
	}

	if (taughtOnTuesday.size() > 0){
		min = max = schedule->getTimeFor(taughtOnTuesday.at(0));
		for (unsigned j = 1; j < taughtOnTuesday.size(); j++){
			if (schedule->getTimeFor(taughtOnTuesday.at(j)) < min){
				min = schedule->getTimeFor(taughtOnTuesday.at(j));
			}
			if (schedule->getTimeFor(taughtOnTuesday.at(j)) > max){
				max = schedule->getTimeFor(taughtOnTuesday.at(j));
			}
		}
		total += max - min + 1;
	}

	if (taughtOnWednesday.size() > 0){
		min = max = schedule->getTimeFor(taughtOnWednesday.at(0));
		for (unsigned j = 1; j < taughtOnWednesday.size(); j++){
			if (schedule->getTimeFor(taughtOnWednesday.at(j)) < min){
				min = schedule->getTimeFor(taughtOnWednesday.at(j));
			}
			if (schedule->getTimeFor(taughtOnWednesday.at(j)) > max){
				max = schedule->getTimeFor(taughtOnWednesday.at(j));
			}
		}
		total += max - min + 1;
	}

	if (taughtOnThursday.size() > 0){
		min = max = schedule->getTimeFor(taughtOnThursday.at(0));
		for (unsigned j = 1; j < taughtOnThursday.size(); j++){
			if (schedule->getTimeFor(taughtOnThursday.at(j)) < min){
				min = schedule->getTimeFor(taughtOnThursday.at(j));
			}
			if (schedule->getTimeFor(taughtOnThursday.at(j)) > max){
				max = schedule->getTimeFor(taughtOnThursday.at(j));
			}
		}
		total += max - min + 1;
	}

	if (taughtOnFriday.size() > 0){
		min = max = schedule->getTimeFor(taughtOnFriday.at(0));
		for (unsigned j = 1; j < taughtOnFriday.size(); j++){
			if (schedule->getTimeFor(taughtOnFriday.at(j)) < min){
				min = schedule->getTimeFor(taughtOnFriday.at(j));
			}
			if (schedule->getTimeFor(taughtOnFriday.at(j)) > max){
				max = schedule->getTimeFor(taughtOnFriday.at(j));
			}
		}
		total += max - min + 1;
	}
	pi.setTotalTime(total);
	double profScore = _sc(pi);
	if (profScore < oldScoreProf){
		pi.setScore(profScore);
	}
	else{
		pi.setScore(oldScoreProf);
	}
	profInfoMap.insert(make_pair(prof.getId(), pi));
	return profScore;
	
}

double GeneticScheduleGenerator::calculateScore(map<string, Prof> professors, Schedule* schedule){
	double score = 0;
	typedef map < string, Prof>::iterator it;
	//map<string, ProfInfo> profInfoMap;
	for (it iterator = professors.begin(); iterator != professors.end(); iterator++){
		ProfInfo pi(iterator->second);
		vector<Course> taughtOnMonday;
		vector<Course> taughtOnTuesday;
		vector<Course> taughtOnWednesday;
		vector<Course> taughtOnThursday;
		vector<Course> taughtOnFriday;
		vector<Course> coursesTaughtByProfessor = schedule->getCoursesTaughtBy(iterator->second);
		pi.setNumCourses(coursesTaughtByProfessor.size());
		set <Weekdays> daysOnCampusSet;
		for (unsigned int i = 0; i < coursesTaughtByProfessor.size(); i++){


			vector<Weekdays> daysForCourse = schedule->getWeekdaysFor(coursesTaughtByProfessor.at(i));

			for (unsigned int j = 0; j < daysForCourse.size(); j++){
				daysOnCampusSet.insert(daysForCourse.at(j));
				switch (daysForCourse.at(j)){
				case MON:
					taughtOnMonday.push_back(coursesTaughtByProfessor.at(i));
					break;
				case TUES:
					taughtOnTuesday.push_back(coursesTaughtByProfessor.at(i));
					break;
				case WED:
					taughtOnWednesday.push_back(coursesTaughtByProfessor.at(i));
					break;
				case THURS:
					taughtOnThursday.push_back(coursesTaughtByProfessor.at(i));
					break;
				case FRI:
					taughtOnFriday.push_back(coursesTaughtByProfessor.at(i));
					break;
				}
			}
			pi.setDaysOnCampus(daysOnCampusSet.size());

		}
		int min, max, total = 0;
		if (taughtOnMonday.size() > 0){
			min = max = schedule->getTimeFor(taughtOnMonday.at(0));
			for (unsigned j = 1; j < taughtOnMonday.size(); j++){
				if (schedule->getTimeFor(taughtOnMonday.at(j)) < min){
					min = schedule->getTimeFor(taughtOnMonday.at(j));
				}
				if (schedule->getTimeFor(taughtOnMonday.at(j)) > max){
					max = schedule->getTimeFor(taughtOnMonday.at(j));
				}
			}
			total += max - min + 1;
		}

		if (taughtOnTuesday.size() > 0){
			min = max = schedule->getTimeFor(taughtOnTuesday.at(0));
			for (unsigned j = 1; j < taughtOnTuesday.size(); j++){
				if (schedule->getTimeFor(taughtOnTuesday.at(j)) < min){
					min = schedule->getTimeFor(taughtOnTuesday.at(j));
				}
				if (schedule->getTimeFor(taughtOnTuesday.at(j)) > max){
					max = schedule->getTimeFor(taughtOnTuesday.at(j));
				}
			}
			total += max - min + 1;
		}

		if (taughtOnWednesday.size() > 0){
			min = max = schedule->getTimeFor(taughtOnWednesday.at(0));
			for (unsigned j = 1; j < taughtOnWednesday.size(); j++){
				if (schedule->getTimeFor(taughtOnWednesday.at(j)) < min){
					min = schedule->getTimeFor(taughtOnWednesday.at(j));
				}
				if (schedule->getTimeFor(taughtOnWednesday.at(j)) > max){
					max = schedule->getTimeFor(taughtOnWednesday.at(j));
				}
			}
			total += max - min + 1;
		}

		if (taughtOnThursday.size() > 0){
			min = max = schedule->getTimeFor(taughtOnThursday.at(0));
			for (unsigned j = 1; j < taughtOnThursday.size(); j++){
				if (schedule->getTimeFor(taughtOnThursday.at(j)) < min){
					min = schedule->getTimeFor(taughtOnThursday.at(j));
				}
				if (schedule->getTimeFor(taughtOnThursday.at(j)) > max){
					max = schedule->getTimeFor(taughtOnThursday.at(j));
				}
			}
			total += max - min + 1;
		}

		if (taughtOnFriday.size() > 0){
			min = max = schedule->getTimeFor(taughtOnFriday.at(0));
			for (unsigned j = 1; j < taughtOnFriday.size(); j++){
				if (schedule->getTimeFor(taughtOnFriday.at(j)) < min){
					min = schedule->getTimeFor(taughtOnFriday.at(j));
				}
				if (schedule->getTimeFor(taughtOnFriday.at(j)) > max){
					max = schedule->getTimeFor(taughtOnFriday.at(j));
				}
			}
			total += max - min + 1;
		}
		pi.setTotalTime(total);
		double profScore = _sc(pi);
		pi.setScore(profScore);
		score += profScore;
		profInfoMap.insert(make_pair(iterator->first, pi));
	}
	return score;
}

Schedule* GeneticScheduleGenerator::getSchedule(){
	Schedule* bestSchedule = new Schedule(*_schedule);
	delete _schedule;
	//Schedule *_changedSchedule = &_changedSc;
	map<string, Prof> professors = bestSchedule->getProfs();
	
	bestSchedule->setScore(calculateScore(professors, bestSchedule));
	/*typedef map < Room, vector < vector < Course > > >::iterator itRooms;
	for (it iterator = professors.begin(); iterator != professors.end(); iterator++){
		ProfInfo pi(iterator->first);
		for (itRooms itr = bestSchedule->getSchedule().begin(); itr != bestSchedule->getSchedule().end(); itr++){
			for (int i = 0; i < itr->second.size(); i++){

			}
		}
	}*/
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
					string prof1Id = course1.getProfId();
					string prof2Id = course2.getProfId();
					if (prof2Id.empty()){
						prof2Id = prof1Id;
					}
					else if (prof1Id.empty()){
						prof1Id = prof2Id;
					}
					double oldScoreProf1 = profInfoMap.at(prof1Id).getScore();
					double oldScoreProf2 = (prof1Id == prof2Id ? 0 : profInfoMap.at(prof2Id).getScore());
					profInfoMap.erase(prof1Id);
					profInfoMap.erase(prof2Id);
					Prof prof1 = professors.at(prof1Id);
					Prof prof2 = professors.at(prof2Id);


					//following three lines of code calculate the score based on the professors of swaped classes
					double newProf1Score = calculateScore(prof1, _changedSchedule, oldScoreProf1);
					double newProf2Score = (prof1Id == prof2Id ? 0 : calculateScore(prof2, _changedSchedule, oldScoreProf2));
					double newScore = bestSchedule->getScore() - oldScoreProf1 - oldScoreProf2 + newProf1Score + newProf2Score;

					//following line of code calculates the score based on the whole schedule
					//double newScore = calculateScore(professors, _changedSchedule);

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
