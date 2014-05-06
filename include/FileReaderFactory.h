#ifndef FILEREADERFACTORY_H
#define FILEREADERFACTORY_H

#include "ReaderFactory.h"

/**
 * Implements the ReaderFactory base class to read vectors from files.
 */
class FileReaderFactory : public ReaderFactory
{
public:
    /**
     * Constructor.
     * @param The delimiter used between fields in the files.
     *        Defaults to a comma character (for CSV files).
     */
    FileReaderFactory(char delimiter = ',');
    virtual vector<Course> getCourses(string);
    virtual vector<Prof> getProfs(string);
    virtual vector<Room> getRooms(string);
    /** Gets the character delimiter used between fields in the files. */
    char getDelimiter() { return _delimiter; }
    /** Sets the character delimiter used between fields in the files. */
    void setDelimiter(char delim) { _delimiter = delim; }
private:
    char _delimiter;
};

#endif // FILEREADERFACTORY_H
