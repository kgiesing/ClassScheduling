#pragma once
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
    /** Constructor with filename */
    RoomReader(std::string filename, char delim=',') : FileReader(filename, delim) { }
    std::vector<Room> read ();
};

#endif // ROOMREADER_H
