#include "../include/ScheduleWriter.h"
#include "../include/Weekdays.h"
#include "../include/TimeBlock.h"
#include "../include/Schedule.h"

#include <cctype> // for ispunct
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

void ScheduleWriter::setFieldDelimiter(const string delimiter) {
	_delimiter = delimiter;
}

void ScheduleWriter::setContents(Schedule *contents) {
	_contents = contents;
}

void ScheduleWriter::write() {
	ofstream file;

	file.open(this->getFilename().c_str());

	//key.
	file << "CE - Course Enrollment" << endl << "RC - Room Capacity" << endl << endl;

	// Score
	file << "Score: " << _contents->getScore() << endl << endl;

	for(int weekday = MON; weekday < WEEKDAYS_SIZE; weekday++) {
		Weekdays w = (Weekdays) weekday;
		for(int block = START_08_00; block < TIMEBLOCK_SIZE; block++) {
			TimeBlock t = (TimeBlock) block;

			file << w << " at " << t << ":\n\n";
			vector<Course> courses = _contents->getCoursesAt(w, t);

			//header
			printCourseLine(file, _delimiter, "Course ID", "Course Name", "Room", "Professor", "CE", "RC");

			//breaker line.
			file << setfill('-');
			printCourseLine(file, _delimiter, "-", "-", "-", "-", "-", "-");
			file << setfill(' ');

			//the output.

			for(unsigned i = 0; i < courses.size(); i++) {
				Room r = _contents->getRoomFor(courses[i]);
				Prof p = _contents->getProf(courses[i]);

				stringstream enrolled, capacity;
				enrolled << courses[i].getEnrolled();
				capacity << r.getCapacity();

				printCourseLine(file, _delimiter, courses[i].getId(), courses[i].getName(),
					r.getId(), p.getLastName(), enrolled.str(), capacity.str());
			}

			file << endl << endl;
		}
	}

	file.close();
}

string ScheduleWriter::ellipsize(const string& input, unsigned maxLength)
{
    // Sanity check
    if (input.length() <= maxLength || maxLength < 3)
        return input;
    unsigned pos = maxLength - 3; // Account for 3-char ellipsis
    // Find the last word boundary before the max length
    while (input[pos] != ' ' && pos > 0)
        pos--;
    // If last char is punctuation, it can be replaced
    while (ispunct(input[pos]) && pos > 0)
        pos--;
    // If position is zero, put ellipsis in the middle of the word
    if (pos == 0)
        pos = maxLength - 3;
    // Return the substring, with the ellipsis appended
    return input.substr(0, pos) + "...";
}

void ScheduleWriter::printCourseLine(ostream& f, const string& _delimiter, const string& courseID,
	const string& courseName, const string& room, const string& prof, const string& enrollment,
	const string& capacity) {

	// delimiter is best " | ", 3 characters.
	f << left << setw(14) << ellipsize(courseID, 14) << _delimiter
	<< setw(25) << ellipsize(courseName, 25) << _delimiter
	<< setw(14) << ellipsize(room, 14) << _delimiter
	<< setw(14) << ellipsize(prof, 14) << _delimiter
	<< setw(2) << enrollment << _delimiter
	<< setw(2) << capacity << endl;
}
