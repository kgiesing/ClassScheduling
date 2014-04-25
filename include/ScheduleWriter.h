#ifndef SCHEDULEWRITER_H
#define SCHEDULEWRITER_H

#include "FileWriter.h"
#include "Schedule.h"

class ScheduleWriter : public FileWriter<Schedule> {
public:
    ScheduleWriter(std::string delimiter = "\t");
    setFieldDelimiter(std::string delimiter);
    setContents(Schedule contents);
private:
    std::string _delimiter;
};

#endif // SCHEDULEWRITER_H
