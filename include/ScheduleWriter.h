#pragma once
#ifndef SCHEDULEWRITER_H
#define SCHEDULEWRITER_H

#include "FileWriter.h"
#include "Schedule.h"

class ScheduleWriter : public FileWriter<Schedule*> {
public:
    ScheduleWriter(std::string filename, std::string delimiter = "\t") : FileWriter(filename) , _delimiter(delimiter) { };
    void setFieldDelimiter(const std::string delimiter);
    void setContents(Schedule *contents);
    void write();
private:
    std::string _delimiter;
    Schedule *_contents;
    void printCourseLine(const string&, const string&, const string&, const string&, const string&, const string&, const string&);
    /** "Ellipsizes" string, so it won't go past a specific length. */
    string ellipsize(const string&, unsigned);
};

#endif // SCHEDULEWRITER_H
