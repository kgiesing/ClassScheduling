#ifndef COMPARABLE_H
#define COMPARABLE_H

/**
 * This class is the base class for all objects that can be compared to
 * each other using the comparison operators.
 */
template <class T>
class Comparable {
public:
  bool operator== (const T& rhs) const { return this->compare(rhs) == 0; }
  bool operator!= (const T& rhs) const { return !(*this == rhs); }
  bool operator<  (const T& rhs) const { return this->compare(rhs) < 0; }
  bool operator<= (const T& rhs) const { return (*this == rhs) || (*this < rhs); }
  bool operator>  (const T& rhs) const { return this->compare(rhs) > 0; }
  bool operator>= (const T& rhs) const { return (*this == rhs) || (*this > rhs); }
protected:
  /**
   * Compares this object to an object on the right hand side. Implementing
   * classes should follow these rules:
   * - If the object has an ID, and the ID of the RHS matches the ID of this
   *   object, then this function should return 0, regardless of any other
   *   member variables.
   * - Otherwise, the function should sort by whatever member variables are
   *   appropriate.
   *
   * @param rhs The object on the right-hand side of the comparison operator.
   * @return 0 if objects are equal; a negative number if this object is
   *         "less than" the RHS object; and a positive number otherwise.
   *
   */
  virtual int compare (const T& rhs) const = 0;
};

#endif // COMPARABLE_H
