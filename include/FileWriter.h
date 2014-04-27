#pragma once
#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
#include "Writer.h"

/**
 * Abstract base class for objects that write something to file.
 */
template <typename T>
class FileWriter : public Writer<T> {
public:
    /**
     * Returns the file name.
     * @return std::string The file name.
     */
    std::string getFilename(void) { return _filename; }

    /**
     * Sets the file name.
     * @param filename const std::string& The file name.
     */
    void setFilename(const std::string& filename) { _filename = filename; }
protected:
    FileWriter(std::string filename) : _filename(filename) { }
private:
    std::string _filename;
};

#endif // FILEWRITER_H
