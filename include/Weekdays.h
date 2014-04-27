#pragma once
#ifndef WEEKDAYS_H
#define WEEKDAYS_H

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

#endif // WEEKDAYS_H
