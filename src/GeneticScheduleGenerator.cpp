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
	Schedule* bestSchedule = _schedule;
	Schedule _changedSc = *_schedule;
	Schedule *_changedSchedule = &_changedSc;
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
	vector<Room> rooms = _schedule->getRooms();
	int numberOfRooms = rooms.size();
	Room room1, room2;
	Weekdays day1, day2;
	TimeBlock time1, time2;
	
	long endTime = time(0) + getTimeout();
	int counter = 0;
	do{
		counter++;
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
			bestSchedule = _schedule;
			/*string profId1 = _changedSchedule->getCourse(room1, day1, time1).getProfId();
			string profId2 = _changedSchedule->getCourse(room2, day2, time2).getProfId();
			
			ProfInfo* profInfo1;
			ProfInfo* profInfo2;
			double scoreProf1 = 0;
			double scoreProf2 = 0;
			map<string, Prof> changedProfs;
			if (profId1 != ""){
				*profInfo1 = profInfoMap.at(profId1);
				scoreProf1 = profInfo1->getScore();
				changedProfs.insert(make_pair(profId1, professors.at(profId1)));
			}
			if (profId2 != ""){
				*profInfo2 = profInfoMap.at(profId2);
				scoreProf2 = profInfo2->getScore();
				changedProfs.insert(make_pair(profId2, professors.at(profId2)));
			}

			
			double currentScore = _changedSchedule->getScore() - scoreProf1 - scoreProf2;*/
			
			
			_changedSchedule->swapCourses(room1, day1, time1, room2, day2, time2);
			double newScore = calculateScore(professors, _changedSchedule);

			if (bestSchedule->getScore() > newScore){
				_schedule = _changedSchedule;
				_schedule->setScore(newScore);
			}
		}
		
	} while (time(0) < endTime);
	std::cout << "counter: " << counter << endl;
	return _schedule;
}

void GeneticScheduleGenerator::optimize(){

}

