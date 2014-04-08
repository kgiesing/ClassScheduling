#ifndef ROOMREADER_H
#define ROOMREADER_H


#include "FileReader.h"

/// class RoomReader -
class RoomReader : public FileReader {
  // Operations
  vector<Room> read ();
};

#endif // ROOMREADER_H
