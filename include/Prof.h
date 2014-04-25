#ifndef PROF_H
#define PROF_H

#include <string>
#include "Comparable.h"

/**
 * This class represents a single professor.
 */
class Prof : private Comparable<Prof> {
public:
    /**
     * Constructor.
     * @param Professor ID.
     * @param First name of professor.
     * @param Last name of professor.
     */
    Prof(const std::string& id, const std::string& firstName,
         const std::string& lastName);
    /**
     * Returns the first name of the professor.
     * @return The first name of the professor.
     */
    const std::string& getFirstName() const { return _firstName; }
    /**
     * Returns the last name of the professor.
     * @return The last name of the professor.
     */
    const std::string& getLastName() const { return _lastName; }
    /**
     * Returns the id of the professor.
     * @return The id of the professor.
     */
    const std::string& getId() const { return _id; }
    /**
     * Sets the first name of the professor.
     * @param The first name of the professor.
     */
    void setFirstName(const std::string& firstName) { _firstName = _firstName; }
    /**
     * Sets the last name of the professor.
     * @param The last name of the professor.
     */
    void setLastName(const std::string& lastName) { _lastName = lastName; }
    /**
     * Sets the ID of the professor.
     * @param The ID of the professor.
     */
    void setId(const std::string& id) { _id = id; }
private:
    std::string _id;
    std::string _firstName;
    std::string _lastName;
    int compare(const Prof& rhs) const;
};

#endif // PROF_H
