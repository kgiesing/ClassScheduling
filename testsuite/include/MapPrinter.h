#ifndef MAPPRINTER_H
#define MAPPRINTER_H

#include "../../include/Course.h"
#include "../../include/Prof.h"
#include "../../include/ProfInfo.h"
#include "../../include/Room.h"
#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::ostream;
using std::string;
using std::map;

class MapPrinter
{
public:
    /**
     * Prints a map of string-to-Course objects to an output stream.
     * @param std::map<string, Course> to print
     * @param std::string to print before every new line
     * @param std::ostream to output Course map; defaults to std::cout
     */
    static void print(const map<string, Course>&, string="", ostream& = cout);
    /**
     * Prints a map of string-to-Prof objects to an output stream.
     * @param std::map<string, Course> to print
     * @param std::string to print before every new line
     * @param std::ostream to output Prof map; defaults to std::cout
     */
    static void print(const map<string, Prof>&, string="", ostream& = cout);
    /**
     * Prints a map of string-to-ProfInfo objects to an output stream.
     * @param std::map<string, Course> to print
     * @param std::string to print before every new line
     * @param std::ostream to output Prof map; defaults to std::cout
     */
    static void print(const map<string, ProfInfo>&, string="", ostream& = cout);
    /**
     * Prints a map of string-to-pointers-to-ProfInfo objects to an output
     * stream.
     * @param std::map<string, Course> to print
     * @param std::string to print before every new line
     * @param std::ostream to output Prof map; defaults to std::cout
     */
    static void print(const map<string, ProfInfo*>&, string="", ostream& = cout);
    /**
     * Prints a map of string-to-Room objects to an output stream.
     * @param std::map<string, Course> to print
     * @param std::string to print before every new line
     * @param std::ostream to output Room map; defaults to std::cout
     */
    static void print(const map<string, Room>&, string="", ostream& = cout);
    /**
     * Prints a map of string-to-TimeBlock enum values to an output stream.
     * @param std::map<string, Course> to print
     * @param std::string to print before every new line
     * @param std::ostream to output TimeBlock enum values;
     *        defaults to std::cout
     */
    static void print(const map<string, TimeBlock>&, string="", ostream& = cout);
    /**
     * Prints a map of string-to-Weekday enum values to an output stream.
     * @param std::map<string, Course> print
     * @param std::string to print before every new line
     * @param std::ostream to output Weekday enum values;
     *        defaults to std::cout
     */
    static void print(const map<string, Weekdays>&, string="", ostream& = cout);
private:
    /** Private constructor */
    MapPrinter() { }
};

#endif // MAPPRINTER_H
