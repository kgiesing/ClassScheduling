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

#endif // TIMEBLOCK_H
