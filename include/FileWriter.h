#pragma once
#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
#include "Writer.h"

using std::string;

/**
 * Abstract base class for objects that write something to file.
 */
template <typename T>
class FileWriter : public Writer<T> {
public:
    /** Virtual destructor. */
    virtual ~FileWriter(void) { }
    /**
     * Returns the file name.
     * @return The file name.
     */
    virtual string getFilename(void) { return _filename; }
    /**
     * Sets the file name.
     * @param The file name.
     */
    virtual void setFilename(const string& filename) { _filename = filename; }
protected:
    /** Protected constructor. */
    FileWriter(string filename) : _filename(filename) { }
private:
    string _filename;
};

#endif // FILEWRITER_H
