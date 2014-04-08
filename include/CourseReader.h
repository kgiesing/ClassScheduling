#ifndef COURSEREADER_H
#define COURSEREADER_H

#include "FileReader.h"

/// class CourseReader -
class CourseReader : public FileReader {
  // Operations
  vector<Course> read ();
};

#endif // COURSEREADER_H
