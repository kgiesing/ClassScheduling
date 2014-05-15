#include "../include/GeneticScheduleGenerator.h"
#include "../include/Weekdays.h"
#include "../include/TimeBlock.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

using std::make_pair;

// DEBUG
#include "../testsuite/include/MapPrinter.h"
#include "../testsuite/include/ObjectPrinter.h"

GeneticScheduleGenerator::GeneticScheduleGenerator(ScoreCalculator& sc,
        Schedule* schedule, long timeout)
    : ScheduleGenerator(timeout) , _sc(sc), _schedule(schedule) { }

Schedule* GeneticScheduleGenerator::getSchedule()
{
    // Declare variables
    bool ok;
    Course c1, c2;
    Room room1, room2;
    Weekdays day1, day2;
    TimeBlock time1, time2;
    set<string> conflicts1, conflicts2;
    vector<Course> others1, others2;

    // DEBUG
    cout << "\nCalculating current score...";
    // Calculate the score for the current schedule
    calculateScore(_schedule);
    // DEBUG
    cout << "\nCurrent score: " _schedule->getScore();

    cout << "\nEvolving ";
    // Swap random courses until the time runs out
    srand(time(NULL));
    vector<Room> rooms = _schedule->getRooms();
    while(time(NULL) < getTimeout())
    {
        room1 = rooms[rand() % rooms.size()];
        room2 = rooms[rand() % rooms.size()];
        day1  = static_cast<Weekdays>(rand() % END_OF_WEEK);
        day2  = static_cast<Weekdays>(rand() % END_OF_WEEK);
        time1 = static_cast<TimeBlock>(rand() % TIMEBLOCK_SIZE);
        time2 = static_cast<TimeBlock>(rand() % TIMEBLOCK_SIZE);

        // Make sure swapped courses would obey constraints
        if (!obeysConstraints(room1, day1, time1, room2, day2, time2))
        {
            cout << "x"; // "still-born"
            continue;
        }
        // Get courses to test
        c1 = _schedule->getCourse(room1, day1, time1);
        c2 = _schedule->getCourse(room2, day2, time2);

        cout << "."; // To show the user we're still working...
        // Generate a mutation
        _mutation = new Schedule(*_schedule);
        _mutation->swapCourses(room1, day1, time1, room2, day2, time2);

        // Calculate the score with the mutation and the duplicate map
        calculateScore(_mutation);

        // Keep the "most fit"
        if(_mutation->getScore() < _schedule->getScore())
        {
            // Swap Schedules
            Schedule* temp = _mutation;
            _mutation = _schedule;
            _schedule = temp;

            // DEBUG
            cout << "a";
        }
        else
            cout << ".";

        // The "least fit" does not survive
        delete _mutation;
    }
    return _schedule;
}

void GeneticScheduleGenerator::calculateScore(Schedule* s)
{
    int addlTime = 0;
    double score = 0;
    string pid;
    ProfInfo* pi;
    TimeBlock tb;
    Weekdays wd;
    map<string, ProfInfo*> info;      // professor ID's to ProfInfo ptrs
    map<string, TimeBlock> firstTime; // professor ID's to first TimeBlock
    map<string, TimeBlock> lastTime;  // professor ID's to last TimeBlock
    map<string, Weekdays> lastDay;    // professor ID's to last Weekday
    map<string, Prof> profs = s->getProfs();
    map<string, Prof>::iterator it;
    map<string, ProfInfo*>::iterator itInfo;
    vector<Room> rooms = s->getRooms();

    for(it = profs.begin(); it != profs.end(); it++)
    {
        firstTime.insert(make_pair(it->first, TIMEBLOCK_SIZE));
        lastTime.insert(make_pair(it->first, TIMEBLOCK_SIZE));
        lastDay.insert(make_pair(it->first, WEEKDAYS_SIZE));
        pi = new ProfInfo(it->second);
        // Get the number of courses taught from the schedule
        int numCourses = s->getCoursesTaughtBy(it->second).size();
        pi->setNumCourses(numCourses);
        info.insert(make_pair(it->first, pi));
    }

    // Iterate over the entire schedule
    for(unsigned r = 0; r < rooms.size(); r++)
    {
        for(int d = MON; d < END_OF_WEEK; d++)
        {
            for(int t = START_08_00; t < TIMEBLOCK_SIZE; t++)
            {
                wd  = static_cast<Weekdays>(d);
                tb  = static_cast<TimeBlock>(t);
                pid = s->getCourse(rooms[r], wd, tb).getProfId();
                if(pid == "") // No course scheduled
                    continue;
                pi = info[pid];
                if(lastDay[pid] != wd)
                {
                    // Add a day
                    pi->setDaysOnCampus(pi->getDaysOnCampus() + 1);
                    lastDay[pid] = wd;
                    // Reset times
                    firstTime[pid] = TIMEBLOCK_SIZE;
                    lastTime[pid]  = TIMEBLOCK_SIZE;
                }
                if(firstTime[pid] > tb)
                {
                    addlTime = 1;
                    firstTime[pid] = tb;
                    lastTime[pid]  = tb;
                }
                if(lastTime[pid] < tb)
                {
                    addlTime = tb - lastTime[pid];
                    lastTime[pid] = tb;
                }
                pi->setTotalTime(pi->getTotalTime() + addlTime);
                // Overwrite the score with result from ScoreCalculator
                pi->setScore(_sc(*pi));
            }
        }
    }
    // Calculate the total score for the Schedule
    for(itInfo = info.begin(); itInfo != info.end(); itInfo++)
    {
        score += itInfo->second->getScore();
        // We're done with ProfInfo; delete objects
        delete itInfo->second;
    }
    s->setScore(score);

}

bool GeneticScheduleGenerator::obeysConstraints(Room room1,
        Weekdays day1, TimeBlock time1, Room room2, Weekdays day2,
        TimeBlock time2)
{
    // Get courses to test
    c1 = _schedule->getCourse(room1, day1, time1);
    c2 = _schedule->getCourse(room2, day2, time2);
    // Don't swap the same courses (duh)
    if(c1 == c2)
        return false;
    // Don't swap courses with the same Prof
    if(c1.getProfId() == c2.getProfId())
        return false;
    // Don't swap courses if the rooms can't hold them
    if(room1.getCapacity() < c2.getEnrolled())
        return false;
    if(room2.getCapacity() < c1.getEnrolled())
        return false;
    // Make sure courses don't conflict with each other
    conflicts1 = c1.getConflicts();
    conflicts2 = c2.getConflicts();
    if (conflicts1.find(c2.getId()) != conflicts1.end())
        return false;
    if (conflicts2.find(c1.getId()) != conflicts2.end())
        return false;
    // Make sure other scheduled courses don't conflict
    others1 = _schedule->getCoursesAt(day1, time1);
    others2 = _schedule->getCoursesAt(day2, time2);
    for (int i = 0; i < others1.size(); i++)
    {
        if (conflicts2.find(others1[i].getId()) != conflicts2.end())
            return false;
    }
    for (int i = 0; i < others2.size(); i++)
    {
        if (conflicts1.find(others2[i].getId()) != conflicts1.end())
            return false;
    }
    return true;
}

