#include "../include/GeneticScheduleGenerator.h"


GeneticScheduleGenerator::GeneticScheduleGenerator(ScoreCalculator& sc, Schedule* schedule, long timeout )
	: ScheduleGenerator(timeout) , _sc(sc) {
		_schedule = schedule;
}


Schedule* GeneticScheduleGenerator::getSchedule(){
	
}

void GeneticScheduleGenerator::optimize(){

}