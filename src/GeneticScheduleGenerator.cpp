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
    : ScheduleGenerator(timeout) , _sc(sc), _schedule(schedule)
{
    // Load up the map
    _info = new map<string, ProfInfo*>();
    map<string, Prof> profs = schedule->getProfs();
    map<string, Prof>::iterator it;
    ProfInfo* pi;
    for(it = profs.begin(); it != profs.end(); it++)
    {
        pi = new ProfInfo(it->second);
        // Get the number of courses taught from the schedule
        int numCourses = schedule->getCoursesTaughtBy(it->second).size();
        pi->setNumCourses(numCourses);
        _info->insert(make_pair(it->first, pi));
    }
}

GeneticScheduleGenerator::~GeneticScheduleGenerator(void)
{
    // DEBUG
    cout << "\nDestructor called...";
    // Delete the contents of the map
    map<string, ProfInfo*>::iterator it;
    for(it = _info->begin(); it != _info->end(); it++)
        delete it->second;
}

Schedule* GeneticScheduleGenerator::getSchedule()
{
    // Declare variables
    Course c1, c2;
    Room room1, room2;
    Weekdays day1, day2;
    TimeBlock time1, time2;
    ProfInfo* pi;
    map<string, ProfInfo*>::iterator it;

    // DEBUG
    cout << "\nCalculating current score...";
    // Calculate the score for the current schedule
    calculateScore(_schedule, *_info);
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

        // Get courses to test
        c1 = _schedule->getCourse(room1, day1, time1);
        c1 = _schedule->getCourse(room1, day1, time1);
        // Don't swap the same courses (duh)
        if(c1 == c2)
            continue;
        // Don't swap courses with the same Prof
        if(c1.getProfId() == c2.getProfId())
            continue;
        // Don't swap courses if the rooms can't hold them
        if(room1.getCapacity() < c2.getEnrolled())
            continue;
        if(room2.getCapacity() < c1.getEnrolled())
            continue;

        cout << "."; // To show the user we're still working...
        // Generate a mutation
        _mutation = new Schedule(*_schedule);
        _mutation->swapCourses(room1, day1, time1, room2, day2, time2);

        // Duplicate the ProfInfo map
        _mnfo = new map<string, ProfInfo*>();
        for(it = _info->begin(); it != _info->end(); it++)
        {
            pi = new ProfInfo(it->second->getProf());
            // Get the number of courses taught from _info
            int numCourses = it->second->getNumCourses();
            pi->setNumCourses(numCourses);
            _mnfo->insert(make_pair(it->first, pi));
        }
        // Calculate the score with the mutation and the duplicate map
        calculateScore(_mutation, *_mnfo);

        // Keep the "most fit"
        if(_mutation->getScore() < _schedule->getScore())
        {
            // Swap Schedules
            Schedule* temp = _mutation;
            _mutation = _schedule;
            _schedule = temp;
            // Swap ProfInfo maps
            map<string, ProfInfo*>* tmpMap = _mnfo;
            _mnfo = _info;
            _info = tmpMap;

            // DEBUG
            cout << "\nFitter specimen found: " << _schedule->getScore();
        }

        // The "least fit" does not survive
        for(it = _mnfo->begin(); it != _mnfo->end(); it++)
            delete it->second;
        delete _mnfo;
        delete _mutation;
    }
    return _schedule;
}

void GeneticScheduleGenerator::calculateScore(Schedule* s,
        map<string, ProfInfo*> info)
{
    int addlTime = 0;
    double score = 0;
    string pid;
    ProfInfo* pi;
    TimeBlock tb;
    Weekdays wd;
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
        score += itInfo->second->getScore();
    s->setScore(score);
}
