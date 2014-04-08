#ifndef ROOM_H
#define ROOM_H

#include "Comparable.h"

/// class Room -
class Room : public Comparable {
  // Attributes
private:
  int _capacity;
  std::string _id;
  // Operations
public:
  int getCapacity () const;
  std::string getId () const;
  bool compare (const Prof& rhs) const;
};

#endif // ROOM_H
