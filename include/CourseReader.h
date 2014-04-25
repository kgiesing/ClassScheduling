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
    std::vector<Course> read();
};

#endif // COURSEREADER_H
