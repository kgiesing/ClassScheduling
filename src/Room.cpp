#include "../include/Room.h"

Room::Room(const std::string& id, int capacity)
    : _id(id), _capacity(capacity) { }

int Room::compare(const Room& rhs) const
{
    // Check ID's
    if (_id.compare(rhs._id) == 0)
        return 0;
    // ID's don't match; does capacity?
    if (_capacity == rhs._capacity)
    {
        // Different rooms with same capacity; compare ID's
        return _id.compare(rhs._id);
    }
    // Capacity doesn't match
    return _capacity - rhs._capacity;
}
