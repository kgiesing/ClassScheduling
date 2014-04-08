#ifndef PROFREADER_H
#define PROFREADER_H

#include "FileReader.h"

/// class ProfReader -
class ProfReader : public FileReader {
  // Operations
  vector<Prof> read ();
};

#endif // PROFREADER_H
