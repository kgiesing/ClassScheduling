#pragma once
#ifndef WEEKDAYS_H
#define WEEKDAYS_H

#include <iostream>

/**
 * Enumeration of the days of the week. The final value is a "dummy value"
 * that represents the "size" of the enum; it is for iterating through the
 * enum's values. (This trick only works with continuous enum values.)
 */
enum Weekdays {
  MON,          /**< Monday (0) */
  TUES,         /**< Tuesday (1)*/
  WED,          /**< Wednesday (2) */
  THURS,        /**< Thursday (3) */
  FRI,          /**< Friday (4) */
  WEEKDAYS_SIZE /**< Dummy value for iterating through enum */
};

/**
 * Overwrite stream output for Weekdays.
 */

inline std::ostream& operator<<(std::ostream& out, const Weekdays value) {
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

#endif // WEEKDAYS_H
