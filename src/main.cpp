#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

// Including these so they'll be built
#include "../include/Schedule.h"
#include "../include/ReaderFactory.h"
#include "../include/FileReaderFactory.h"
#include "../include/ConflictPreprocessor.h"
#include "../include/ScheduleGenerator.h"
#include "../include/ScoreCalculator.h"
#include "../include/LinearScoreCalculator.h"
#include "../include/WeightedScoreCalculator.h"
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

  //delimiter is a char value;
  char delimiterN;
  bool newDelimiter = false;

  //default timer for generator
  long time = 1000;

  //score calculator selector
  bool defCal = true;
  ScoreCalculator* calculator;

  //default value for output file
  outputN = "schedule.txt";

  if(argc < 4)
    {
      cout << "No enough arguments are typed in" << endl;
      return 0;
    }

  int i = 1;

  //if "-o output" appears at beginning, record the output file name
  //if "-d delimiter" appears at beginning, record the new delimiter
  //if "-t times" appears at beginning, record the new times
  //if "-w" appears at beginning, use WeightedScoreCalculator
  //if "-l" appears at beginning, use LinearScoreCalculator
  std::string c;
  while((c = argv[i]) == "-o" || c == "-d" || c == "-w" || c == "-l" || c == "-t")
    if (c == "-o") {
      outputN = argv[++i];
      i++;
    } else if (c == "-d"){
      newDelimiter = true;
      delimiterN = argv[++i][0];
      i++;
    } else if (c == "-l"){
      i++;
    } else if (c == "-w"){
      defCal = false;
      i++;
    } else {
      //using atol from stdlib to convert char array to long
      time = atol(argv[++i]);
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
  ReaderFactory* reader;

  //set delimiter if necessary
  if(newDelimiter)
    reader = new FileReaderFactory(delimiterN);
  else
    reader = new FileReaderFactory();

  roomV = reader->getRooms(roomN);
  profV = reader->getProfs(profN);
  courseV = reader->getCourses(courseN);
  delete reader;

  //add conflict
  ConflictPreprocessor::preprocess(courseV);

  ScheduleGenerator* generator;

  //Form the schedule by using greedy algorithm
  //Will be changed depends on implementation of GreedyScheduler
  generator = new GreedyScheduleGenerator(roomV, profV, courseV, time);
  schedule = generator->getSchedule();
  delete generator;


  //if user does not indicate calculator, linear score calculator
  //will be used.
  if(defCal)
    calculator = new LinearScoreCalculator();
  else
    calculator = new WeightedScoreCalculator();

  //Try to optimize the schedule
  //Will be changed depends on implementation of GeneticScheduler
  generator = new GeneticScheduleGenerator(*calculator, schedule, time);
  schedule = generator->getSchedule();
  delete generator;
  delete calculator;

  //Write schedule
  //Will be changed denpends on implementation of ScheduleWriter
  ScheduleWriter writer(outputN);
  writer.setContents(schedule);
  writer.write();

  return 0;
}
