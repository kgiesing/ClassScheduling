#ifndef DATACREATOR_H
#define DATACREATOR_H

#include "../include/Course.h"
#include "../include/Prof.h"
#include "../include/Room.h"
#include <vector>

using std::vector;

/**
 * This class is used to create test data.
 */
class DataCreator
{
public:
    /** Creates a random Course object. */
    static Course createCourse(void);
    /** Creates a random Prof object. */
    static Prof createProf(void);
    /** Creates a random Room object. */
    static Room createRoom(void);
    /**
     * Creates a vector of a specific size, filled with random Course objects.
     * The number of objects is randomized; the second parameter is only the
     * suggested size of the vector to create.
     * @param Object used as type for overloading. Otherwise ignored.
     * @param Maximum number of members to create. Default 20.
     * @return std::vector of random Course objects.
     */
    static vector<Course> createVector(Course, int = 20);
    /**
     * Creates a vector of a specific size, filled with random Prof objects.
     * The number of objects is randomized; the second parameter is only the
     * suggested size of the vector to create.
     * @param Object used as type for overloading. Otherwise ignored.
     * @param Maximum number of members to create. Default 20.
     * @return std::vector of random Prof objects.
     */
    static vector<Prof> createVector(Prof, int = 20);
    /**
     * Creates a vector of a specific size, filled with random Room objects.
     * The number of objects is randomized; the second parameter is only the
     * suggested size of the vector to create.
     * @param Object used as type for overloading. Otherwise ignored.
     * @param Maximum number of members to create. Default 20.
     * @return std::vector of random Room objects.
     */
    static vector<Room> createVector(Room, int = 20);
private:
    /** Private constructor */
    DataCreator(void) { }
};

#endif // DATACREATOR_H
