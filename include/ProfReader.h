#ifndef PROFREADER_H
#define PROFREADER_H

#include <vector>
#include "FileReader.h"
#include "Prof.h"

/**
 * This class reads a list of Prof objects from a CSV file.
 */
class ProfReader : public FileReader< std::vector<Prof> > {
public:
    std::vector<Prof> read();
};

#endif // PROFREADER_H