#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Course.h"
#include "Prof.h"
#include "Room.h"
#include "TimeBlock.h"
#include "Weekdays.h"
#include "ScoreCalculator.h"
#include <map>
#include <vector>

using std::map;
using std::string;
using std::vector;

/**
 * This class represents a schedule for all courses.
 */
class Schedule {
public:
    /** Default constructor. */
	Schedule(void) { }
    /**
     * Constructs the Schedule using vectors returned from the Reader classes.
     * @param std::vector of Room objects
     * @param std::vector of Prof objects
     * @param std::vector of Course objects
     */
	Schedule(vector<Room>, vector<Prof>, vector<Course>);
	/** Copy constructor. */
	Schedule(const Schedule& schedule);
	/** Overloaded assignment operator. */
	Schedule& operator=(const Schedule&);
    /**
     * Gets a course scheduled at a given room, day, and time.
     * @param The room in which a course is taught.
     * @param THe day on which a course is taught.
     * @param THe time in which a course is taught.
     * @return Course scheduled for that room at that day and time.
     *         If no course is scheduled, will return a default Course object
     *         whose information is blank.
     */
	Course getCourse(const Room&, Weekdays, TimeBlock);
    /**
     * Gets a courses scheduled on a given day and time.
     * @param THe day on which courses are taught.
     * @param THe time in which courses are taught.
     * @return std::vector of Course objects scheduled at that day and time.
     */
	vector<Course > getCoursesAt(Weekdays, TimeBlock);
    /**
     * Gets all the courses taught by a specific professor.
     * @param The professor.
     * @return std::vector of Courses taught by the professor.
     */
	vector<Course> getCoursesTaughtBy(Prof&);
    /**
     * Gets all the courses taught by a specific professor on a specific day.
     * @param The professor.
     * @return std::vector of Courses taught by the professor on that day.
     */
	vector<Course> getCoursesOnGivenDayTaughtBy(Prof&, Weekdays);
    /**
     * Gets the Prof object associated with a specific ID.
     * @param The professor's ID.
     * @return The Prof object associated with the ID.
     */
    Prof getProf(string);
    /**
     * Gets the professor who teaches a specific course.
     * @param The course.
     * @return The professor who teaches the course.
     */
	Prof getProf(Course);
    /**
     * Gets a map of all the professors in the schedule, keyed by their ID's.
     * @return std::map of ID's to Prof objects.
     */
	map<string, Prof> getProfs(void);
    /**
     * Gets the room in which a course is scheduled.
     * @param The course.
     * @return Rom in which a course is scheduled.
     */
	Room getRoomFor(const Course&);
    /**
     * Gets all the rooms in the schedule.
     * @return std::vector of all the Rooms in the schedule.
     */
	vector<Room> getRooms(void);
	/** Returns the internals of this object. */
	map<Room, vector< vector<Course> > > getSchedule();
    /**
     * Gets the score for this schedule.
     * @return The score for this schedule.
     */
	double getScore(void) { return _score; }
    /**
     * Gets the times in which a course is scheduled.
     * @param The course.
     * @return std::vector of TimeBlock enums on which a course is scheduled.
     */
	TimeBlock getTimeFor(const Course&);
    /**
     * Gets the days on which a course is scheduled.
     * @param The course.
     * @return std::vector of Weekdays enums on which a course is scheduled.
     */
	vector<Weekdays> getWeekdaysFor(const Course&);
    /**
     * Sets a course for a given room, day, and time.
     * @param The course to set.
     * @param The room to assign the course.
     * @param The day on which the course is taught.
     * @param The time on which the course is taught.
     * @return True if setting the course was successful; false otherwise.
     *
     */
	bool setCourse(const Course&, const Room&, Weekdays, TimeBlock);
    /**
     * Sets the score for this schedule.
     * @param The score for this schedule.
     */
	void setScore(double score){ _score = score; }
    /**
     * Swaps the courses in the given rooms at the given days and times.
     * @param Room for the first course to swap.
     * @param Weekday for the first course to swap.
     * @param Time for the first course to swap.
     * @param Room for the second course to swap.
     * @param Weekday for the second course to swap.
     * @param Time for the second course to swap.
     * @return True if swapping is successful, false otherwise.
     */
	bool swapCourses(Room, Weekdays, TimeBlock, Room, Weekdays, TimeBlock);
private:
	map<Room, vector< vector<Course> > > _schedule;
	map<string, Prof> _professors;
	map<string, Course> _courses;
	vector<Room> _rooms;
	double _score;
};

#endif // SCHEDULE_H
