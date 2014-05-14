#ifndef SCHEDULESCORECALC_H
#define SCHEDULESCORECALC_H

#include <map>
#include <string>

using std::map;
using std::string;

class ScheduleScoreCalc
{
public:
    /** Default constructor */
    ScheduleScoreCalc() {}
    static map<string, ProfInfo*> loadScores(Schedule* s, ScoreCalculator& sc)
    {
        map <string, Prof>::iterator it;
        // Create a map of professor ID's to ProfInfo objects
        map<string, ProfInfo*> info;
        // Create a map of professor ID's to first time on campus
        map<string, TimeBlock> firstTime;
        // Create a map of professor ID's to the latest weekday
        map<string, Weekdays> lastDay;
        // Load them up
        for (it = s->getProfs().begin(); it != s->getProfs().end(); it++)
        {
            ProfInfo* pi = new ProfInfo(it->second);
            info[it->first] = pi;
            // Get the number of courses taught from the schedule
            info[it->first]->setNumCourses(s->getCoursesTaughtBy(it->second).size());
            firstTime[it->first] = TIMEBLOCK_SIZE;
            lastDay[it->first] = WEEKDAYS_SIZE;
        }

        // Iterate over the entire schedule
        vector<Room> rooms = s->getRooms();
        for (unsigned r = 0; r < rooms.size(); r++)
        {
            for (int d = MON; d < WEEKDAYS_SIZE; d++)
            {
                int todaysTime = 0;
                for (int t = START_08_00; t < TIMEBLOCK_SIZE; t++)
                {
                    Weekdays wd = static_cast<Weekdays>(d);
                    TimeBlock tb = static_cast<TimeBlock>(t);
                    string pid = s->getCourse(rooms[r], wd, tb).getProfId();
                    if (pid == "")
                        continue; // No course scheduled
                    ProfInfo* pi = info[pid];
                    if (lastDay[pid] != wd)
                    {
                        // Another day
                        lastDay[pid] = wd;
                        firstTime[pid] = tb;
                        pi->setDaysOnCampus(pi->getDaysOnCampus() + 1);
                        pi->setTotalTime(pi->getTotalTime() + todaysTime);
                    }
                    if (firstTime[pid] > tb)
                        firstTime[pid] = tb;
                    todaysTime = tb - firstTime[pid] + 1;
                    // Overwrite the score with the new information
                    pi->setScore(sc(*pi));
                }
            }
        }
        // Return the map
        return info;
    }
};

#endif // SCHEDULESCORECALC_H
