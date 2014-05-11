#pragma once
#ifndef TIMEBLOCK_H
#define TIMEBLOCK_H

/**
 * Enumeration of daily time blocks. The final value is a "dummy value"
 * that represents the "size" of the enum; it is for iterating through the
 * enum's values. (This trick only works with continuous enum values.)
 */
enum TimeBlock {
  START_08_00,
  START_09_30,
  START_11_00,
  START_12_30,
  START_14_00,
  START_15_30,
  START_17_00,
  START_18_30,
  START_20_00,
  TIMEBLOCK_SIZE /**< Dummy value for iterating through enum */
};

/*
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


#endif // TIMEBLOCK_H
