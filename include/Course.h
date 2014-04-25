#ifndef COURSE_H
#define COURSE_H

#include <vector>
#include <string>
#include "Comparable.h"

/**
 * This class represents a single course.
 */
class Course : private Comparable<Course> {
public:
    /**
     * Constructor.
     * @param Course ID.
     * @param Course name.
     * @param Number of students enrolled in the course.
     * @param ID of professor who teaches the course.
     * @param List of conflicting courses.
     */
    Course(const std::string& id, const std::string& name, int enrolled,
           const std::string& profId, const std::vector<std::string>& conflicts);
    /**
     * Returns the number of students enrolled in the course.
     * @return The number of students enrolled in the course.
     */
    const int& getEnrolled() const { return _enrolled; }
    /**
     * Returns the course ID.
     * @return The course ID.
     */
    const std::string& getId() const { return _id; }
    /**
     * Returns the ID of the professor who teaches this course.
     * @return The ID of the professor who teaches this course.
     */
    const std::string& getProfId() const { return _profId; }
    /**
     * Returns the ID's of the courses that conflict with this course.
     * @return A constant vector containing the ID's of the courses that
     *         conflict with this course.
     */
    const std::vector<std::string>& getConflicts() const { return _conflicts; }
    /**
     * Returns the ID's of the courses that conflict with this course.
     * @return A mutable vector containing the ID's of the courses that
     *         conflict with this course.
     */
    std::vector<std::string>& getConflicts() { return _conflicts; }
    /**
     * Sets the number of students enrolled in the course.
     * @param The number of students enrolled in the course.
     */
    void setEnrolled(int enrolled) { _enrolled = enrolled; }
    /**
     * Sets the course ID.
     * @param The course ID.
     */
    void setId(const std::string& id) const { _id = id; }
    /**
     * Sets the ID of the professor who teaches this course.
     * @param The ID of the professor who teaches this course.
     */
    void setProfId(const std::string& profId) const { _profId = profId; }
    /**
     * Sets the ID's of the courses that conflict with this course.
     * @param A constant vector containing the ID's of the courses that
     *         conflict with this course.
     */
     void setConflicts(const std::vector<std::string>& conflicts)
            { _conflicts = conflicts; }
private:
    std::string _id;
    std::string _name;
    int _enrolled;
    std::string _profId;
    std::vector<std::string> _conflicts;
    int compare (const Course& rhs) const;
};

#endif // COURSE_H
