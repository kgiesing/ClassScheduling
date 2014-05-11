#ifndef VECTORPRINTER_H
#define VECTORPRINTER_H

#include "../include/Course.h"
#include "../include/Prof.h"
#include "../include/ProfInfo.h"
#include "../include/Room.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::ostream;
using std::string;
using std::vector;

class VectorPrinter
{
public:
    /**
     * Prints a vector of Course objects to an output stream.
     * @param std::vector of Course objects to print
     * @param std::string to print before every new line
     * @param std::ostream to output Course vector; defaults to std::cout
     */
    static void print(const vector<Course>&, string="", ostream& = cout);
    /**
     * Prints a vector of Prof objects to an output stream.
     * @param std::vector of Prof objects to print
     * @param std::string to print before every new line
     * @param std::ostream to output Prof vector; defaults to std::cout
     */
    static void print(const vector<Prof>&, string="", ostream& = cout);
    /**
     * Prints a vector of Prof objects to an output stream.
     * @param std::vector of Prof objects to print
     * @param std::string to print before every new line
     * @param std::ostream to output Prof vector; defaults to std::cout
     */
    static void print(const vector<ProfInfo>&, string="", ostream& = cout);
    /**
     * Prints a vector of Room objects to an output stream.
     * @param std::vector of Room objects to print
     * @param std::string to print before every new line
     * @param std::ostream to output Room vector; defaults to std::cout
     */
    static void print(const vector<Room>&, string="", ostream& = cout);
    /**
     * Prints a vector of TimeBlock enum values to an output stream.
     * @param std::vector of TimeBlock enum values to print
     * @param std::string to print before every new line
     * @param std::ostream to output TimeBlock enum values;
     *        defaults to std::cout
     */
    static void print(const vector<TimeBlock>&, string="", ostream& = cout);
    /**
     * Prints a vector of Weekday enum values to an output stream.
     * @param std::vector of Weekday enum values to print
     * @param std::string to print before every new line
     * @param std::ostream to output Weekday enum values;
     *        defaults to std::cout
     */
    static void print(const vector<Weekdays>&, string="", ostream& = cout);
private:
    /** Private constructor */
    VectorPrinter() { }
};

#endif // VECTORPRINTER_H
