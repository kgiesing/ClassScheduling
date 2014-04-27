#pragma once
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "Comparable.h"

/**
 * This class represents a single room.
 */
class Room : public Comparable<Room> {
public:
    /**
     * Constructor.
     * @param Room capacity.
     * @param Room ID.
     */
    Room(const std::string& id, int capacity);
    /**
     * Returns the room capacity.
     * @return Constant reference to the room capacity.
     */
    const int& getCapacity() const { return _capacity; }
    /**
     * Returns the room ID.
     * @return Constant reference to the room ID.
     */
    const std::string& getId() const { return _id; }
    /**
     * Sets the room capacity.
     * @return Constant reference to the room capacity.
     */
    void setCapacity(int capacity) { _capacity = capacity; }
    /**
     * Sets the room ID.
     * @return Constant reference to the room ID.
     */
    void setId(const std::string& id) { _id = id; }
private:
    std::string _id;
    int _capacity;
    int compare(const Room& rhs) const;
};

#endif // ROOM_H
