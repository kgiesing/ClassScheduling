#ifndef READERFACTORY_H
#define READERFACTORY_H

#include "Course.h"
#include "Prof.h"
#include "Room.h"
#include <string>s
#include <vector>

using std::string;
using std::vector;

/**
 * This class acts as a pure virtual base class for a reader factory.
 * Implementing factory classes should use different Reader subclasses to read
 * the vecotrs of Course, Prof, or Room objects from some data source, such as
 * a database or file(s).
 */
class ReaderFactory
{
public:
    /**
     * Reads a vector of Course objects.
     * @param A string representing a path to a resource.
     */
    virtual vector<Course> getCourses(string) = 0;
    /**
     * Reads a vector of Prof objects.
     * @param A string representing a path to a resource.
     */
    virtual vector<Prof> getProfs(string) = 0;
    /**
     * Reads a vector of Room objects.
     * @param A string representing a path to a resource.
     */
    virtual vector<Room> getRooms(string) = 0;
protected:
    /** Protected no-arg constructor. */
    ReaderFactory() {}
};

#endif // READERFACTORY_H
