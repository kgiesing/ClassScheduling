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

void ScheduleWriter::write() {
	ofstream file;
	
	file.open(this->getFilename().c_str());
	
	for(Weekdays w = MON; w < WEEKDAYS_SIZE; w++) {
		for(TimeBlock t = START_08_00; t < TIMEBLOCK_SIZE; t++) {
			file << w << " at " << t << ":\n\n";
			vector<Course> courses = _contents->getCoursesAt(w, t);
			
			for(int i = 0; i < courses.size(); i++) {
				Room r = _contents->getRoomFor(courses[i]);
				file << courses[i].getId() << _delimiter
					 << courses[i].getName() << _delimiter
					 << r.getId() << _delimiter
					 << (_contents->getProf(courses[i])).getId() << _delimiter
					 << courses[i].getEnrolled() << _delimiter
					 << r.getCapacity() << "\n";
			}
			
			file << "\n\n";
		}
	}
	
	file.close();
}
