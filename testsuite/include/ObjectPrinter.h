#ifndef OBJECTPRINTER_H
#define OBJECTPRINTER_H

#include <iostream>
#include <string>
#include "../include/Course.h"
#include "../include/Prof.h"
#include "../include/ProfInfo.h"
#include "../include/Room.h"

using std::cout;
using std::ostream;
using std::string;

class ObjectPrinter
{
public:
    static void print(const Course&,   string="", ostream& = cout);
    static void print(const Prof&,     string="", ostream& = cout);
    static void print(const ProfInfo&, string="", ostream& = cout);
    static void print(const Room&,     string="", ostream& = cout);
private:
    /** Private constructor */
    ObjectPrinter() { }
};

#endif // OBJECTPRINTER_H
