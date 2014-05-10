#include "../include/Prof.h"

Prof::Prof(const std::string& id, const std::string& firstName,
           const std::string& lastName) :
    _id(id), _firstName(firstName), _lastName(lastName) { }

int Prof::compare(const Prof& rhs) const
{
    // Check ID's
    if (_id == rhs._id)
        return 0;
    // ID's don't match; does last name?
    if (_lastName.compare(rhs._lastName) == 0)
    {
        // Last name matches, so sort by first name
        if (_firstName.compare(rhs._firstName) == 0)
        {
            // Professor with the same name, so compare ID's
            return _id.compare(rhs._id);
        }
        // Last name matches, first name doesn't
        return _firstName.compare(rhs._firstName);
    }
    // Last name doesn't match
    return _lastName.compare(rhs._lastName);
}
