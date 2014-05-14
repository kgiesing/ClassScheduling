#ifndef DATACREATOR_H
#define DATACREATOR_H

#include "../../include/Course.h"
#include "../../include/Prof.h"
#include "../../include/Room.h"
#include "../../include/Schedule.h"
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
    /** Creates a random (possibly invalid) Schedule object. */
    static Schedule createSchedule(void);
    /**
     * Creates a vector of a specific size, filled with random Course objects.
     * The number of objects is randomized; the second parameter is only the
     * suggested size of the vector to create.
     * @param Object used as type for overloading. Otherwise ignored.
     * @param Suggested number of members to create. Default 20.
     * @return std::vector of random Course objects.
     */
    static vector<Course> createVector(Course, int = 20);
    /**
     * Creates a vector of a specific size, filled with random Prof objects.
     * The number of objects is randomized; the second parameter is only the
     * suggested size of the vector to create.
     * @param Object used as type for overloading. Otherwise ignored.
     * @param Suggested number of members to create. Default 20.
     * @return std::vector of random Prof objects.
     */
    static vector<Prof> createVector(Prof, int = 20);
    /**
     * Creates a vector of a specific size, filled with random Room objects.
     * The number of objects is randomized; the second parameter is only the
     * suggested size of the vector to create.
     * @param Object used as type for overloading. Otherwise ignored.
     * @param Suggested number of members to create. Default 20.
     * @return std::vector of random Room objects.
     */
    static vector<Room> createVector(Room, int = 20);
    /**
     * Creates a CSV files from a vector of a specific size, filled with
     * random Course objects.
     * The number of objects is randomized; the second parameter is only the
     * suggested size of the vector to create.
     * @param File name, including path.
     * @param Object used as type for overloading. Otherwise ignored.
     * @param Suggested number of members to create. Default 20.
     * @return true if file creation was successful; false otherwise.
     */
    static bool createVectorFile(string, Course, int = 20);
    /**
     * Creates a CSV files from a vector of a specific size, filled with
     * random Prof objects.
     * The number of objects is randomized; the second parameter is only the
     * suggested size of the vector to create.
     * @param File name, including path.
     * @param Object used as type for overloading. Otherwise ignored.
     * @param Suggested number of members to create. Default 20.
     * @return true if file creation was successful; false otherwise.
     */
    static bool createVectorFile(string, Prof, int = 20);
    /**
     * Creates a CSV files from a vector of a specific size, filled with
     * random Room objects.
     * The number of objects is randomized; the second parameter is only the
     * suggested size of the vector to create.
     * @param File name, including path.
     * @param Object used as type for overloading. Otherwise ignored.
     * @param Suggested number of members to create. Default 20.
     * @return true if file creation was successful; false otherwise.
     */
    static bool createVectorFile(string, Room, int = 20);
    /**
     * Loads the vector of Course objects with random Prof ID's from the
     * vector of Prof objects.
     * @param Mutable vector of Course objects.
     * @param Constant vector of Prof objects.
     */
    static void loadProfs(vector<Course>&, const vector<Prof>&);
private:
    /** Private constructor */
    DataCreator(void) { }
};

#endif // DATACREATOR_H
