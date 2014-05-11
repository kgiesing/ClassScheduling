#include "../include/FileReaderFactory.h"
#include "../include/CourseReader.h"
#include "../include/ProfReader.h"
#include "../include/RoomReader.h"

FileReaderFactory::FileReaderFactory(char delimiter) :
    _delimiter(delimiter) { }

vector<Course> FileReaderFactory::getCourses(string filename)
{
    CourseReader reader(filename, _delimiter);
    return reader.read();
}

vector<Prof> FileReaderFactory::getProfs(string filename)
{
    ProfReader reader(filename, _delimiter);
    return reader.read();

}

vector<Room> FileReaderFactory::getRooms(string filename)
{
    RoomReader reader(filename, _delimiter);
    return reader.read();
}
