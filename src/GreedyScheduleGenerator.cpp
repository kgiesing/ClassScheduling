#include <vector>
#include <set>
#include <iostream>
#include "../include/GreedyScheduleGenerator.h"
#include "../include/Weekdays.h"
#include "../include/TimeBlock.h"
#include <stdexcept> // For exceptions

using std::runtime_error;

GreedyScheduleGenerator::GreedyScheduleGenerator(vector<Room>& rooms,
        vector<Prof>& profs, vector<Course>& courses, long timeout)
    : ScheduleGenerator(timeout), _rooms(rooms), _profs(profs), _courses(courses),
      _isScheduled(courses.size()), _isFull(rooms.size())
{
    // Create a map of course ID's to course indexes, for finding conflicts
    for(unsigned i = 0; i < courses.size(); i++)
        _courseMap[courses[i].getId()] = i;

}


Schedule* GreedyScheduleGenerator::getSchedule()
{
    //  Declare variables
    TimeBlock time;
    Weekdays day;
    unsigned idxRoom;

    // Create the (empty) Schedule object
    _schedule = new Schedule(_rooms, _profs, _courses);

    // Schedule courses by matching capacities to enrollment
    idxRoom = 0;
    day = MON;
    time = START_08_00;
    for(unsigned c = 0; c < _courses.size(); c++)
    {
        // Skip if it was scheduled as a conflict
        if (_isScheduled[c])
            continue;
        _isFull[idxRoom] = findNextTime(_rooms[idxRoom], day, time);
        while(_isFull[idxRoom] && idxRoom < _rooms.size())
        {
            time = START_08_00;
            day = MON;
            idxRoom++;
            _isFull[idxRoom] = findNextTime(_rooms[idxRoom], day, time);
        }
        if (idxRoom == _rooms.size())
            throw runtime_error("Cannot create valid schedule: all rooms full");

        if (_rooms[idxRoom].getCapacity() < _courses[c].getEnrolled())
            throw runtime_error("Cannot create valid schedule: courses are too large");

        _schedule->setCourse(_courses[c], _rooms[idxRoom], day, time);
        // Schedule the conflicting courses
        set<string> conflicts = _courses[c].getConflicts();
        for(set<string>::iterator it = conflicts.begin(); it != conflicts.end(); it++)
        {
            unsigned conflict;
            try {
                conflict = _courseMap.at(*it);
                scheduleConflict(conflict, time);
            }
            catch (...) {
                // Conflicting course does not exist in vector...
                // Throw an error, fail without message, or what?
            }
        }
        _isScheduled[c] = true;
    }

    // Done.
    return _schedule;
}

bool GreedyScheduleGenerator::findNextTime(const Room r, Weekdays& day,
        TimeBlock& time)
{
    // To reset day and time
    Weekdays oldDay = day;
    TimeBlock oldTime = time;

    while(_schedule->getCourse(r, day, time).getId() != "")
    {
        time = static_cast<TimeBlock>(time + 1);
        if(time >= TIMEBLOCK_SIZE)
        {
            day = static_cast<Weekdays>(day + 1);
            time = START_08_00;
            if(day > LAST_DAY)
            {
                // No "next time" for this room...
                day = oldDay;
                time = oldTime;
                return true;
            }
        }
    }
    return false;
}

void GreedyScheduleGenerator::scheduleConflict(unsigned c, TimeBlock time)
{
    bool full;
    // Starting at room with lowest possible capacity and work upwards
    unsigned idxRoom = 0;
    while(idxRoom < _rooms.size() && _rooms[idxRoom].getCapacity() >= _courses[c].getEnrolled())
        idxRoom++;
    idxRoom--; // Went past it; back up one
    if(idxRoom < 0)
        throw runtime_error("Cannot create valid schedule: courses are too large");

    // Schedule this course at a different time
    TimeBlock tb = START_08_00;
    Weekdays day = MON;

    full = findNextTime(_rooms[idxRoom], day, tb);
    while (tb == time || (full && idxRoom > 0))
    {
        if(tb == time)  // Conflicts with original
            tb = static_cast<TimeBlock>(tb + 1);
        else // Room was full
        {
            time = START_08_00;
            day = MON;
            idxRoom--;
        }
        full = findNextTime(_rooms[idxRoom], day, tb);
    }
    if (full)
        throw runtime_error("Cannot create valid schedule: all rooms full");

    _schedule->setCourse(_courses[c], _rooms[idxRoom], day, time);
    _isScheduled[c] = true;
}
