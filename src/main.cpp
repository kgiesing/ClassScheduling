#include <iostream>
#include <vector>

// Including these so they'll be built
#include "../include/CourseReader.h"
#include "../include/RoomReader.h"
#include "../include/ProfReader.h"
#include "../include/Schedule.h"
#include "../include/Reader.h"
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
  std::string roomN, courseN, profN, outputN;

  //default value for output file, might be changed
  outputN = "Schedule.txt"; 
  
  /* simple implementation for command line interface, will be changed by Gavin */

  if(argc == 1)
    {
      cout << "No arguments are typed in" << endl;
      return 0;
    }

  int index = 1;

  //if "-o output" appears at beginning, record the output file name 
  if((std::string c = argv[i]) == "-o")
    {
      outputN = argv[++i];
      i++;
    }

  //read three files' name in order, order might be changed.
  roomN = argv[i++];
  profN = argv[i++];
  courseN = argv[i++];

  //if "-o output" appear at end, record the output file name
  if((std::string c = argv[i]) == "-o")
    outputN = argv[++i];

  /* end of implementation of command line interface */

  //vectors that will contain data
  std::vector<Room> roomV;
  std::vector<Prof> profV;
  std::vector<Course> courseV;
  
  //Read the data
  Reader* reader;
 
  reader = new RoomReader(roomN);
  roomV = reader->read();
  delete reader;

  reader = new ProfReader(profN);
  profV = reader->read();
  delete reader;

  reader = new CourseReader(courseN);
  courseV = reader->read();
  delete reader;
  
  //Form the schedule by using greedy algorithm
  //Will be changed depends on implementation of GreedyScheduler
  GreedyScheduleGenerator greScheduler(roomV, profV, courseV);
  schedule = greScheduler.getSchedule();
  
  //Try to optimize the schedule
  //Will be changed depends on implementation of GeneticScheduler
  GeneticScheduleGenerator genScheduler(schedule);
  schedule = genScheduler.getSchedule();
  
  //Write schedule
  //Will be changed denpends on implementation of ScheduleWriter
  ScheduleWriter writer(outputN);
  writer.setContents(schedule);
  writer.write();
  
  return 0;
}
