#ifndef VECTORPRINTER_H
#define VECTORPRINTER_H

#include "../include/Course.h"
#include "../include/Prof.h"
#include "../include/Room.h"
#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::ostream;

class VectorPrinter
{
public:
    /**
     * Prints a vector of Course objects to an output stream.
     * @param std::vector of Course objects to print
     * @param std::ostream to output Course vector; defaults to std::cout
     */
    static void print(const vector<Course>&, ostream& = cout);
    /**
     * Prints a vector of Prof objects to an output stream.
     * @param std::vector of Prof objects to print
     * @param std::ostream to output Prof vector; defaults to std::cout
     */
    static void print(const vector<Prof>&, ostream& = cout);
    /**
     * Prints a vector of Room objects to an output stream.
     * @param std::vector of Room objects to print
     * @param std::ostream to output Room vector; defaults to std::cout
     */
    static void print(const vector<Room>&, ostream& = cout);
private:
    /** Private constructor */
    VectorPrinter() { }
};

#endif // VECTORPRINTER_H
