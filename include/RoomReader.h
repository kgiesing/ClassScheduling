#ifndef ROOMREADER_H
#define ROOMREADER_H

#include <vector>
#include "FileReader.h"
#include "Room.h"

/**
 * This class reads a list of Room objects from a CSV file.
 */
class RoomReader : public FileReader< std::vector<Room> > {
public:
    std::vector<Room> read ();
};

#endif // ROOMREADER_H
