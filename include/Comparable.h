#ifndef COMPARABLE_H
#define COMPARABLE_H

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
  virtual int compare (const T& rhs) const = 0;
};

#endif // COMPARABLE_H
