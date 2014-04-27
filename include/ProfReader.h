#pragma once
#ifndef PROFREADER_H
#define PROFREADER_H

#include <vector>
#include "FileReader.h"
#include "Prof.h"

/**
 * This class reads a list of Prof objects from a CSV file.
 *
 * Prof CSV file fields: professor ID, professor name
 */
class ProfReader : public FileReader< std::vector<Prof> > {
public:
    /** Constructor with filename */
    ProfReader(std::string filename, char delim=',') : FileReader(filename, delim) { }
    std::vector<Prof> read();
};

#endif // PROFREADER_H
