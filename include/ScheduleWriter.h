#ifndef SCHEDULEWRITER_H
#define SCHEDULEWRITER_H

#include "FileWriter.h"

/// class ScheduleWriter -
class ScheduleWriter : public FileWriter {
  // Operations
public:
  setFieldDelimiter (std::string delimiter = "\t");
  setContents (Schedule contents);
};

#endif // SCHEDULEWRITER_H
