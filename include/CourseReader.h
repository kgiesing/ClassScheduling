#pragma once
#ifndef COURSEREADER_H
#define COURSEREADER_H

#include <vector>
#include "FileReader.h"
#include "Course.h"

/**
 * This class reads a list of Course objects from a CSV file.
 */
class CourseReader : public FileReader< std::vector<Course> > {
public:
    /** Constructor with filename */
    CourseReader(std::string filename, char delim=',') : FileReader(filename, delim) { }
    std::vector<Course> read();
};

#endif // COURSEREADER_H
