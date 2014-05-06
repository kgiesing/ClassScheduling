#include "FileReaderFactory.h"
#include "CourseReader.h"
#include "ProfReader.h"
#include "RoomReader.h"

FileReaderFactory::FileReaderFactory(char delimiter) :
    _delimiter(delimiter) { }

vector<Course> FileReaderFactory::getCourses(string filename)
{
    CourseReader reader(filename, _delimiter);
    return reader.read();
}

vector FileReaderFactory::getProfs(string filename)
{
    ProfReader reader(filename, _delimiter);
    return reader.read();

}

vector FileReaderFactory::getRooms(string filename)
{
    RoomReader reader(filename, _delimiter);
    return reader.read();
}
