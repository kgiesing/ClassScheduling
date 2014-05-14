#include <vector>
#include <set>
#include <iostream>
#include "../include/GreedyScheduleGenerator.h"
#include "../include/Weekdays.h"
#include "../include/TimeBlock.h"


Schedule* GreedyScheduleGenerator::getSchedule() {
	Schedule* schedule = new Schedule(_rooms, _profs, _courses);

}
