#ifndef FILEREADER_H
#define FILEREADER_H

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
    std::string getFilename(void) { return _filename; }

    /**
     * Sets the file name.
     * @param filename const std::string& The file name.
     */
    void setFilename(const std::string& filename) { _filename = filename; }
protected:
    FileReader(std::string filename) : _filename(filename) { }
private:
    std::string _filename;
};

#endif // FILEREADER_H
