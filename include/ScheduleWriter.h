#ifndef SCHEDULEWRITER_H
#define SCHEDULEWRITER_H

#include "FileWriter.h"
#include "Schedule.h"

class ScheduleWriter : public FileWriter<Schedule> {
public:
    ScheduleWriter(std::string delimiter = "\t");
    void setFieldDelimiter(std::string delimiter);
    void setContents(Schedule contents);
private:
    std::string _delimiter;
};

#endif // SCHEDULEWRITER_H
