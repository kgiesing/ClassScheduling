#pragma once
#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include "Reader.h"

using std::string;

/**
 * Abstract base class for objects that read something from file.
 */
template <typename T>
class FileReader : public Reader<T> {
public:
    /**
     * Returns the file name.
     * @return string The file name.
     */
    virtual string getFilename(void) const { return _filename; }

    /**
     * Returns the delimiter between fields in the file.
     * @return string The file name.
     */
    virtual char getDelimiter(void) const { return _delim; }

    /**
     * Sets the file name.
     * @param filename const string& The file name.
     */
    virtual void setFilename(const string& filename) { _filename = filename; }

    /**
     * Sets the the delimiter between fields in the file.
     * @param delim char The the delimiter between fields in the file.
     */
    virtual void setDelimiter(char delim) { _delim = delim; }
protected:
    FileReader(string filename, char delim=',') : _filename(filename), _delim(delim) { }
private:
    string _filename;
    char _delim;
};

#endif // FILEREADER_H
