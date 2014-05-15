#include "../include/Schedule.h"
#include "../include/Prof.h"
#include <vector>
#include <set>
#include <string>

using namespace std;

/**
 * Constructor for the schedule. Creates the empty schedule
 */
Schedule::Schedule(vector < Room > rooms, vector < Prof > prof, vector < Course > courses){
	_rooms = rooms;
	for(unsigned i = 0; i < prof.size(); i++){
			_professors.insert(make_pair(prof.at(i).getId(), prof.at(i)));
	}
	for (unsigned i = 0; i < courses.size(); i++){
		_courses.insert(make_pair(courses.at(i).getId(), courses.at(i)));
	}
	_score = -1;
	for (unsigned i = 0; i < _rooms.size(); i++){
		vector < vector < Course > > dayVector;
		dayVector.resize(WEEKDAYS_SIZE);
		for (unsigned j = 0; j < dayVector.size(); j++){
			dayVector.at(j).resize(TIMEBLOCK_SIZE);
		}
		_schedule.insert(make_pair(_rooms.at(i), dayVector));
	}
}

bool Schedule::setCourse(const Course& course, const Room& room, Weekdays firstMeeting, TimeBlock timeBlock){
	if (course.getEnrolled() > room.getCapacity()){
		return false;
	}
	int numberOfTimeBlocks = course.getTimeBlocks();
	switch (numberOfTimeBlocks){
	case 2:
		if (firstMeeting > TUES){
			return false;
		}
		break;
	}
	_schedule.at(room).at(firstMeeting).at(timeBlock) = course;

	switch (numberOfTimeBlocks){
	case 2:
		_schedule.at(room).at((TimeBlock)(firstMeeting + 2)).at(timeBlock) = course;
		break;
	}
	return true;
}

Course Schedule::getCourse(const Room& room, Weekdays day, TimeBlock timeBlock){
	return _schedule.at(room).at(day).at(timeBlock);
}

vector < Course > Schedule::getCoursesAt(Weekdays day, TimeBlock timeBlock){
	typedef map < Room, vector < vector < Course > > >::iterator it;
	vector < Course > vec;
	for (it iterator = _schedule.begin(); iterator != _schedule.end(); iterator++){
		Room room = iterator->first;
		Course course = getCourse(room, day, timeBlock);
		if (course.getId().compare("") != 0){
			vec.push_back(course);
		}
	}
	return vec;
}

TimeBlock Schedule::getTimeFor(const Course& course){
	typedef map < Room, vector < vector < Course > > >::iterator it;
	for (it iterator = _schedule.begin(); iterator != _schedule.end(); iterator++){
		Room rr = iterator->first;
		vector < vector < Course > > vec = iterator->second;
		for (unsigned i = 0; i < vec.size(); i++){
			for (unsigned j = 0; j < vec.at(i).size(); j++){
				if (course == getCourse(rr, (Weekdays)i, (TimeBlock)j)){
					return (TimeBlock)j;
				}
			}
		}
	}
	//returns TIMEBLOCK_SIZE if course is not scheduled
	return TIMEBLOCK_SIZE;
}

Room Schedule::getRoomFor(const Course& course){
	typedef map < Room, vector < vector < Course > > >::iterator it;
	for (it iterator = _schedule.begin(); iterator != _schedule.end(); iterator++){
		Room rr = iterator->first;
		vector < vector < Course > > vec = iterator->second;
		for (unsigned i = 0; i < vec.size(); i++){
			for (unsigned j = 0; j < vec.at(i).size(); j++){
				if (course == getCourse(rr, (Weekdays)i, (TimeBlock)j)){
					return rr;
				}
			}
		}
	}
	//returns empty room object if course is not scheduled
	Room room;
	return room;
}

vector < Weekdays > Schedule::getWeekdaysFor(const Course& course){
	typedef map < Room, vector < vector < Course > > >::iterator it;
	vector<Weekdays> weekdays;
	for (it iterator = _schedule.begin(); iterator != _schedule.end(); iterator++){
		Room rr = iterator->first;
		vector < vector < Course > > vec = iterator->second;
		for (unsigned i = 0; i < vec.size(); i++){
			for (unsigned j = 0; j < vec.at(i).size(); j++){
				if (course == getCourse(rr, (Weekdays)i, (TimeBlock)j)){
					weekdays.push_back((Weekdays)i);
				}
			}
		}
	}
	/*if (!weekdays.empty()){
		weekdays.push_back((Weekdays)(weekdays.back() + 2));
	}*/
	//returns empty vector if the class is not scheduled
	return weekdays;
}

// returns true if swap was successful, false otherwise
bool Schedule::swapCourses(Room room1, Weekdays weekdays1, TimeBlock timeBlock1, Room room2, Weekdays weekdays2, TimeBlock timeBlock2){
	Course c1, c2;
	if (room1.getCapacity() < c2.getEnrolled() || room2.getCapacity() < c1.getEnrolled()){
		return false;
	}
	else {
		c1 = getCourse(room1, weekdays1, timeBlock1);
		c2 = getCourse(room2, weekdays2, timeBlock2);
		setCourse(c2, room1, weekdays1, timeBlock1);
		setCourse(c1, room2, weekdays2, timeBlock2);
		return true;
	}

}

Prof Schedule::getProf(string id){
	return _professors.at(id);
}

Prof Schedule::getProf(Course c){
	return _professors.at(c.getProfId());
}

map < Room, vector < vector < Course > > > Schedule::getSchedule(){
	return _schedule;
}

Schedule::Schedule(const Schedule& schedule){
	_schedule = schedule._schedule;
	_professors = schedule._professors;
	_courses = schedule._courses;
	_rooms = schedule._rooms;
	_score = schedule._score;
}

vector<Room> Schedule::getRooms(){
	return _rooms;
}

map <string, Prof> Schedule::getProfs(){
	return _professors;
}

vector <Course> Schedule::getCoursesTaughtBy(Prof& prof){
	typedef map<string, Course>::iterator iterator;
	vector <Course> courseVec;
	for (iterator it = _courses.begin(); it != _courses.end(); it++)
	{
		if (prof == getProf(it->second.getProfId())){
			courseVec.push_back(it->second);
		}
	}
	return courseVec;
}

Schedule& Schedule::operator=(const Schedule& rhs){
	_rooms = rhs._rooms;
	_courses = rhs._courses;
	_professors = rhs._professors;
	_schedule = rhs._schedule;
	_score = rhs._score;
	return *this;
}