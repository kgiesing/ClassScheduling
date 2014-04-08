#ifndef COURSE_H
#define COURSE_H

#include "Comparable.h"

/// class Course -
class Course : public Comparable {
  // Attributes
private:
  int _enrolled;
  std::string _id;
  std::string _profId;
  std::string _name;
  std::vector<std::string> _conflicts;
  // Operations
public:
  int getEnrolled () const;
  std::string getId () const;
  std::string getProfId () const;
  std::vector<std::string> getConflicts () const;
  bool compare (const Course& rhs) const;
};

#endif // COURSE_H
