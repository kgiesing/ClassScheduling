#include "../include/ScheduleWriter.h"
#include "../include/Weekdays.h"
#include "../include/TimeBlock.h"
#include "../include/Schedule.h"

#include <fstream>

using std::ofstream;
using std::string;
using std::vector;

void ScheduleWriter::setFieldDelimiter(string delimiter) {
	_delimiter = delimiter;
}

void ScheduleWriter::setContents(Schedule *contents) {
	_contents = contents;
}

void SchedulerWriter::write() {
	ofstream file;
	
	file.open(this->getFileName().c_str());
	
	for(Weekdays w = 0; w < WEEKDAYS_SIZE; w++) {
		for(TimeBlock t = 0; t < TIMEBLOCK_SIZE; t++) {
			file << w << " at " << t << ":\n\n";
			vector<Course> courses = contents->getCoursesAt(w, t);
			
			for(int i = 0; i < courses.size(); i++) {
				file << courses[i].getId() << _delimiter
					 << courses[i].getName() << _delimiter
					 << (contents->getRoomFor(courses[i])).getId() << _delimiter
					 << contents->getProfForCourse(courses[i]) << _delimiter
					 << courses[i].getEnrolled() << "\n";
			}
			
			file << "\n\n";
		}
	}
	
	file.close();
}

/**
 * Overwrite stream output for Weekdays.
 */

std::ostream& operator<<(std::ostream& out, const Weekdays value) {
	switch(value) {
		case MON:
			out << "Monday";
			break;
		case TUES:
			out << "Tuesday";
			break;
		case WED:
			out << "Wednesday";
			break;
		case THURS:
			out << "Thursday";
			break;
		case FRI:
			out << "Friday";
			break;
		case WEEKDAYS_SIZE:	//shouldn't get here!
			out << "Dummy";
	}
	
	return out;
}

/**
 * Overwrite stream output for TimeBlocks.
 */

std::ostream& operator<<(std::ostream& out, const TimeBlock value) {
	switch(value) {
		case START_08_00:
			out << "8:00-9:15 AM";
			break;
		case START_09_30:
			out << "9:30-10:45 AM";
			break;
		case START_11_00:
			out << "11:00AM-12:15PM";
			break;
		case START_12_30:
			out << "12:30-1:45PM";
			break;
		case START_14_00:
			out << "2:00-3:15 PM";
			break;
		case START_15_30:
			out << "3:30-4:45PM";
			break;
		case START_17_00:
			out << "5:00-6:15PM";
			break;
		case START_18_30:
			out << "6:30-7:45PM";
			break;
		case START_20_00:
			out << "8:00-9:15PM";
			break;
		case TIMEBLOCK_SIZE:	//shouldn't get here!
			out << "Dummy";
	}
	
	return out;
}
