#include "../include/Course.h"

std::vector<std::string> temp;
Course::Course(){
	_id = "";
	_name = "";
	_enrolled = 0;
	_profId = "";
	_conflicts = temp;

}

Course::Course(const std::string& id, const std::string& name, int enrolled,
               const std::string& profId, const std::vector<std::string>& conflicts)
    : _id(id), _name(name), _enrolled(enrolled), _profId(profId),
      _conflicts(conflicts) { }

int Course::compare(const Course& rhs) const
{
    // Sort on ID's only
    return _id.compare(rhs._id);
}
