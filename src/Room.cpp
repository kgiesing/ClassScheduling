#include "../../include/Room.h"

Room::Room(const std::string& id, int capacity)
    : _id(id), _capacity(capacity) { }

int Room::compare(const Room& rhs) const
{
    // Check ID's
    if (_id.compare(rhs.getId()) == 0)
        return 0;
    // ID's don't match; does capacity?
    if (_capacity == rhs.getCapacity())
    {
        // Professor with the same name, so compare ID's
        return _id.compare(rhs.getId());
    }
    // Capacity doesn't match
    return rhs.getCapacity() - _capacity;
}
