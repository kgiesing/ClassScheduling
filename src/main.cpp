#include <iostream>
#include <vector>
#include <string>

// Including these so they'll be built
#include "../include/CourseReader.h"
#include "../include/RoomReader.h"
#include "../include/ProfReader.h"
#include "../include/Schedule.h"
#include "../include/ScheduleGenerator.h"
#include "../include/GreedyScheduleGenerator.h"
#include "../include/GeneticScheduleGenerator.h"
#include "../include/ScheduleWriter.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
  Schedule* schedule;
  
  //names for the data files and output file,
  //will get from users by command-line interface.
  std::string roomN, courseN, profN, outputN, delimiterN;
  bool newDelimiter = false;

  //default value for output file
  outputN = "schedule.txt"; 

  if(argc == 1)
    {
      cout << "No arguments are typed in" << endl;
      return 0;
    }

  int i = 1;

  //if "-o output" appears at beginning, record the output file name 
  //if "-d delimiter" appears at beginning, record the new delimiter
  std::string c;
  while((c = argv[i]) == "-o" || c == "-d")
    if (c == "-o") {
      outputN = argv[++i];
      i++;
    } else {
      newDelimiter = true;
      delimiterN = argv[++i];
      i++;
    }

  //read three files' name in order, order might be changed.
  roomN = argv[i++];
  profN = argv[i++];
  courseN = argv[i++];

  //if "-o output" appear at end, record the output file name
  if((c = argv[i]) == "-o")
    outputN = argv[++i];

  /* end of implementation of command line interface */

  //vectors that will contain data
  std::vector<Room> roomV;
  std::vector<Prof> profV;
  std::vector<Course> courseV;
  
  //Read the data
  RoomReader roomR(roomN);
  ProfReader profR(profN);
  CourseReader courseR(courseN);
  
  //set delimiter if necessary
  if(newDelimiter) {
    roomR.setDelimiter(delimiterN);
    profR.setDelimiter(delimiterN);
    courseR.setDelimiter(delimiterN);
  }
  
  roomV = roomR.read();
  profV = profR.read();
  courseV = courseR.read();
  
  ScheduleGenerator* generator;

  //Form the schedule by using greedy algorithm
  //Will be changed depends on implementation of GreedyScheduler
  generator = new GreedyScheduleGenerator(roomV, profV, courseV);
  schedule = generator->getSchedule();
  delete generator;

  //Try to optimize the schedule
  //Will be changed depends on implementation of GeneticScheduler
  generator = new GeneticScheduleGenerator(schedule);
  schedule = generator->getSchedule();
  delete generator;

  //Write schedule
  //Will be changed denpends on implementation of ScheduleWriter
  ScheduleWriter writer(outputN);
  writer.setContents(schedule);
  writer.write();
  
  return 0;
}
