#include "../include/Course.h"

Course::Course() : _id(""), _name(""), _enrolled(0), _profId("") { }

Course::Course(const std::string& id, const std::string& name, int enrolled,
               const std::string& profId, const std::vector<std::string>& conflicts)
    : _id(id), _name(name), _enrolled(enrolled), _profId(profId),
      _conflicts(conflicts) { }

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
