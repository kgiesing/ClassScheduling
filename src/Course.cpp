#include "../include/Course.h"

Course::Course() : _id(""), _name(""), _profId(""), _enrolled(0),
        _timeBlocks(2) { }

Course::Course(const string& id, const string& name, const string& profId,
        int enrolled, int timeBlocks, const set<string>& conflicts)
    : _id(id), _name(name), _profId(profId),_enrolled(enrolled),
        _timeBlocks(timeBlocks), _conflicts(conflicts) { }

int Course::compare(const Course& rhs) const
{
    // Check ID's
    if (_id.compare(rhs._id) == 0)
        return 0;
    // ID's don't match; does enrollment?
    if (_enrolled == rhs._enrolled)
    {
        // Different rooms with same enrollment; compare ID's
        return _id.compare(rhs._id);
    }
    // Enrollment doesn't match
    return _enrolled - rhs._enrolled;
}
