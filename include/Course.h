#pragma once
#ifndef COURSE_H
#define COURSE_H

#include <vector>
#include <string>
#include "Comparable.h"

using std::string;
using std::vector;

/**
 * This class represents a single course.
 */
class Course : public Comparable<Course> {
public:

    /** No-arg constructor. */
	Course(void);

    /**
     * Constructor.
     * @param Course ID.
     * @param Course name.
     * @param Number of students enrolled in the course.
     * @param ID of professor who teaches the course.
     * @param List of conflicting courses.
     */
    Course(const string& id, const string& name, int enrolled,
           const string& profId, const vector<string>& conflicts);
    /**
     * Returns the number of students enrolled in the course.
     * @return The number of students enrolled in the course.
     */
    const int& getEnrolled() const { return _enrolled; }
    /**
     * Returns the course ID.
     * @return The course ID.
     */
    const string& getId() const { return _id; }
    /**
     * Returns the ID of the professor who teaches this course.
     * @return The ID of the professor who teaches this course.
     */
    const string& getProfId() const { return _profId; }
    /**
     * Returns the ID's of the courses that conflict with this course.
     * @return A constant vector containing the ID's of the courses that
     *         conflict with this course.
     */
    const vector<string>& getConflicts() const { return _conflicts; }
    /**
     * Returns the ID's of the courses that conflict with this course.
     * @return A mutable vector containing the ID's of the courses that
     *         conflict with this course.
     */
    vector<string>& getConflicts() { return _conflicts; }
    /**
     * Returns the name of this course.
     * @return The name of this course.
     */
    const string& getName() const { return _name; }
    /**
     * Sets the number of students enrolled in the course.
     * @param The number of students enrolled in the course.
     */
    void setEnrolled(int enrolled) { _enrolled = enrolled; }
    /**
     * Sets the course ID.
     * @param The course ID.
     */
    void setId(const string& id) { _id = id; }
    /**
     * Sets the ID of the professor who teaches this course.
     * @param The ID of the professor who teaches this course.
     */
    void setProfId(const string& profId) { _profId = profId; }
    /**
     * Sets the ID's of the courses that conflict with this course.
     * @param A constant vector containing the ID's of the courses that
     *         conflict with this course.
     */
     void setConflicts(const vector<string>& conflicts)
            { _conflicts = conflicts; }
    /**
     * Sets the name of this course.
     * @param The name of this course.
     */
    void setName(const string& name) { _name = name; }
private:
    string _id;
    string _name;
    int _enrolled;
    string _profId;
    vector<string> _conflicts;
    int compare(const Course& rhs) const;
};

#endif // COURSE_H
