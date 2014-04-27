#pragma once
#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include "Reader.h"

/**
 * Abstract base class for objects that read something from file.
 */
template <typename T>
class FileReader : public Reader<T> {
public:
    /**
     * Returns the file name.
     * @return std::string The file name.
     */
    std::string getFilename(void) const { return _filename; }


    /**
     * Returns the delimiter between fields in the file.
     * @return std::string The file name.
     */
    char getDelimiter(void) const { return _delim; }

    /**
     * Sets the file name.
     * @param filename const std::string& The file name.
     */
    void setFilename(const std::string& filename) { _filename = filename; }

    /**
     * Sets the the delimiter between fields in the file.
     * @param delim char The the delimiter between fields in the file.
     */
    void setDelimiter(char delim) { _delim = delim; }
protected:
    FileReader(std::string filename, char delim=',') : _filename(filename), _delim(delim) { }
private:
    std::string _filename;
    char _delim;
};

#endif // FILEREADER_H
