#ifndef PROF_H
#define PROF_H

#include "Comparable.h"

/// class Prof -
class Prof : public Comparable {
  // Attributes
private:
  std::string _firstName;
  std::string _lastName;
  std::string _id;
  // Operations
public:
  std::string getFirstName () const;
  std::string getLastName () const;
  std::string getId () const;
  bool compare (const Prof& rhs) const;
};

#endif // PROF_H
