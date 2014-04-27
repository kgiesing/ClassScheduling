#pragma once
#ifndef COURSEREADER_H
#define COURSEREADER_H

#include <vector>
#include "FileReader.h"
#include "Course.h"

/**
 * This class reads a list of Course objects from a CSV file.
 *
 * Course CSV file fields: course ID, course name, Professor ID, number of
 * enrolled students (as an integer), number of time periods required by the
 * course (as an integer), list of conflicting course ID’s (if no conflicts
 * exist, this section shall be empty)
 */
class CourseReader : public FileReader< std::vector<Course> > {
public:
    /** Constructor with filename */
    CourseReader(std::string filename, char delim=',') : FileReader(filename, delim) { }
    std::vector<Course> read();
};

#endif // COURSEREADER_H
