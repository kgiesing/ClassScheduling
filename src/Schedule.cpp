#include "../include/Schedule.h"
#include "../include/Prof.h"
#include <vector>
#include <set>
#include <string>

using namespace std;

/**
 * Constructor for the schedule. Creates the empty schedule
 */
Schedule::Schedule(vector < Room > rooms){
	for (int i = 0; i < rooms.size(); i++){
		vector < vector < Course > > dayVector;
		dayVector.resize(WED);
		for (int j = 0; j < dayVector.size(); j++){
			dayVector.at(j).resize(TIMEBLOCK_SIZE);
		}
		_schedule.insert(make_pair(rooms.at(i), dayVector));
	}
}

bool Schedule::setCourse(const Course& course, const Room& room, Weekdays firstMeeting, TimeBlock timeBlock, int numberOfMeetings){
	if (course.getEnrolled() > room.getCapacity()){
		return false;
	}
	_schedule.at(room).at(firstMeeting).at(timeBlock) = course;
	return true;
}

Course Schedule::getCourse(const Room& room, Weekdays day, TimeBlock timeBlock){
	vector < vector < Course > > vect = _schedule.at(room);
	vector<Course> v = vect.at(day);
	string id = v.at(timeBlock).getId();
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
		for (int i = 0; i < vec.size(); i++){
			for (int j = 0; j < vec.at(i).size(); j++){
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
		for (int i = 0; i < vec.size(); i++){
			for (int j = 0; j < vec.at(i).size(); j++){
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
		for (int i = 0; i < vec.size(); i++){
			for (int j = 0; j < vec.at(i).size(); j++){
				if (course == getCourse(rr, (Weekdays)i, (TimeBlock)j)){
					weekdays.push_back((Weekdays)i);
				}
			}
		}
	}
	if (!weekdays.empty()){
		weekdays.push_back((Weekdays)(weekdays.back() + 2));
	}
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
		setCourse(c2, room1, weekdays1, timeBlock1, 2);
		setCourse(c1, room2, weekdays2, timeBlock2, 2);
		return true;
	}
}

double Schedule::calculateScore(vector<Prof> teachingProfessors){
	//set <string> teachingProfessors;

	typedef map < Room, vector < vector < Course > > >::iterator it;
	vector<Weekdays> weekdays;
	for (it iterator = _schedule.begin(); iterator != _schedule.end(); iterator++){
		Room rr = iterator->first;
		vector < vector < Course > > vec = iterator->second;
		for (int i = 0; i < vec.size(); i++){
			for (int j = 0; j < vec.at(i).size(); j++){
				teachingProfessors.insert(getCourse(rr, (Weekdays)i, (TimeBlock)j).getProfId());
			}
		}
	}

	/*typedef vector<Prof>::iterator profIt;
	for (profIt iterator = teachingProfessors.begin(); iterator != teachingProfessors.end(); iterator++){
		(*_sc)(new ProfInfo(iterator));
	}*/
	return 1.0;
}


map < Room, vector < vector < Course > > > Schedule::getSchedule(){
	return _schedule;
}