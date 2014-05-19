#include "../include/ScheduleCalculator.h"
#include "../include/Weekdays.h"
#include "../include/TimeBlock.h"

double ScheduleCalculator::calculateScore(Schedule* s, ScoreCalculator& sc)
{
    int addlTime = 0;
    double score = 0;
    string profId;
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

    for (it = profs.begin(); it != profs.end(); it++)
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

    // Iterate over the entire schedule, by day and time
    for (int d = MON; d < WEEKDAYS_SIZE; d++)
    {
        for (int t = START_08_00; t < TIMEBLOCK_SIZE; t++)
        {
            for (unsigned r = 0; r < rooms.size(); r++)
            {
                wd  = static_cast<Weekdays>(d);
                tb  = static_cast<TimeBlock>(t);
                profId = s->getCourse(rooms[r], wd, tb).getProfId();
                if(profId == "") // No course scheduled
                    continue;
                if (info.find(profId) == info.end()) // Invalid ID!
                    continue;
                pi = info[profId];
                if (lastDay[profId] != wd)
                {
                    // Add a day
                    pi->setDaysOnCampus(pi->getDaysOnCampus() + 1);
                    lastDay[profId] = wd;
                    // Reset times
                    firstTime[profId] = TIMEBLOCK_SIZE;
                    lastTime[profId]  = TIMEBLOCK_SIZE;
                }
                if (firstTime[profId] > tb)
                {
                    addlTime = 1;
                    firstTime[profId] = tb;
                    lastTime[profId]  = tb;
                }
                if (lastTime[profId] < tb)
                {
                    addlTime = tb - lastTime[profId];
                    lastTime[profId] = tb;
                }
                pi->setTotalTime(pi->getTotalTime() + addlTime);
                // Overwrite the score with result from ScoreCalculator
                score = sc(*pi);
                pi->setScore(score);
            }
        }
    }
    // Calculate the total score for the Schedule
    score = 0;
    for(itInfo = info.begin(); itInfo != info.end(); itInfo++)
    {
        score += itInfo->second->getScore();
        // We're done with ProfInfo; delete objects
        delete itInfo->second;
    }
    s->setScore(score);
    return score;
}

