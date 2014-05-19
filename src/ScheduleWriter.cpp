#include "../include/ScheduleWriter.h"
#include "../include/Weekdays.h"
#include "../include/TimeBlock.h"
#include "../include/Schedule.h"

#include <fstream>
#include <iomanip>

using std::ofstream;
using std::setw;
using std::string;
using std::vector;
using std::endl;

void ScheduleWriter::setFieldDelimiter(const string delimiter) {
	_delimiter = delimiter;
}

void ScheduleWriter::setContents(Schedule *contents) {
	_contents = contents;
}

void ScheduleWriter::write() {
	ofstream file;

	file.open(this->getFilename().c_str());

	for(int weekday = MON; weekday < WEEKDAYS_SIZE; weekday++) {
		Weekdays w = (Weekdays) weekday;
		for(int block = START_08_00; block < TIMEBLOCK_SIZE; block++) {
			TimeBlock t = (TimeBlock) block;

			file << w << " at " << t << ":\n\n";
			vector<Course> courses = _contents->getCoursesAt(w, t);

			for(unsigned i = 0; i < courses.size(); i++) {
				Room r = _contents->getRoomFor(courses[i]);
				Prof p = _contents->getProf(courses[i]);
				file << setw(7) << courses[i].getId() << _delimiter
				     << setw(40) << courses[i].getName() << _delimiter
				     << setw(7) << r.getId() << _delimiter
				     << setw(20) << p.getLastName() << ", " << p.getFirstName() << _delimiter
				     << setw(3) << courses[i].getEnrolled() << _delimiter
				     << setw(3) << r.getCapacity() << endl;
			}

			file << endl << endl;
		}
	}

	file.close();
}
