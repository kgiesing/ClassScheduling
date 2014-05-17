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

    // Iterate over the entire schedule
    for (unsigned r = 0; r < rooms.size(); r++)
    {
        for (int d = MON; d < WEEKDAYS_SIZE; d++)
        {
            for (int t = START_08_00; t < TIMEBLOCK_SIZE; t++)
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

double ScheduleCalculator::calculateScore(Schedule* schedule, ScoreCalculator& _sc, map<string, Prof> professors)
{
    std::map<string, ProfInfo> profInfoMap;
    double score = 0;
    typedef map < string, Prof>::iterator it;
    //map<string, ProfInfo> profInfoMap;
    for(it iterator = professors.begin(); iterator != professors.end(); iterator++)
    {
        ProfInfo pi(iterator->second);
        vector<Course> taughtOnMonday;
        vector<Course> taughtOnTuesday;
        vector<Course> taughtOnWednesday;
        vector<Course> taughtOnThursday;
        vector<Course> taughtOnFriday;
        vector<Course> coursesTaughtByProfessor = schedule->getCoursesTaughtBy(
                    iterator->second);
        pi.setNumCourses(coursesTaughtByProfessor.size());
        set <Weekdays> daysOnCampusSet;
        for(unsigned int i = 0; i < coursesTaughtByProfessor.size(); i++)
        {


            vector<Weekdays> daysForCourse = schedule->getWeekdaysFor(
                                                 coursesTaughtByProfessor.at(i));

            for(unsigned int j = 0; j < daysForCourse.size(); j++)
            {
                daysOnCampusSet.insert(daysForCourse.at(j));
                switch(daysForCourse.at(j))
                {
                case MON:
                    taughtOnMonday.push_back(coursesTaughtByProfessor.at(i));
                    break;
                case TUES:
                    taughtOnTuesday.push_back(coursesTaughtByProfessor.at(i));
                    break;
                case WED:
                    taughtOnWednesday.push_back(coursesTaughtByProfessor.at(i));
                    break;
                case THURS:
                    taughtOnThursday.push_back(coursesTaughtByProfessor.at(i));
                    break;
                case FRI:
                    taughtOnFriday.push_back(coursesTaughtByProfessor.at(i));
                    break;
                }
            }
            pi.setDaysOnCampus(daysOnCampusSet.size());

        }
        int min, max, total = 0;
        if(taughtOnMonday.size() > 0)
        {
            min = max = schedule->getTimeFor(taughtOnMonday.at(0));
            for(unsigned j = 1; j < taughtOnMonday.size(); j++)
            {
                if(schedule->getTimeFor(taughtOnMonday.at(j)) < min)
                {
                    min = schedule->getTimeFor(taughtOnMonday.at(j));
                }
                if(schedule->getTimeFor(taughtOnMonday.at(j)) > max)
                {
                    max = schedule->getTimeFor(taughtOnMonday.at(j));
                }
            }
            total += max - min + 1;
        }

        if(taughtOnTuesday.size() > 0)
        {
            min = max = schedule->getTimeFor(taughtOnTuesday.at(0));
            for(unsigned j = 1; j < taughtOnTuesday.size(); j++)
            {
                if(schedule->getTimeFor(taughtOnTuesday.at(j)) < min)
                {
                    min = schedule->getTimeFor(taughtOnTuesday.at(j));
                }
                if(schedule->getTimeFor(taughtOnTuesday.at(j)) > max)
                {
                    max = schedule->getTimeFor(taughtOnTuesday.at(j));
                }
            }
            total += max - min + 1;
        }

        if(taughtOnWednesday.size() > 0)
        {
            min = max = schedule->getTimeFor(taughtOnWednesday.at(0));
            for(unsigned j = 1; j < taughtOnWednesday.size(); j++)
            {
                if(schedule->getTimeFor(taughtOnWednesday.at(j)) < min)
                {
                    min = schedule->getTimeFor(taughtOnWednesday.at(j));
                }
                if(schedule->getTimeFor(taughtOnWednesday.at(j)) > max)
                {
                    max = schedule->getTimeFor(taughtOnWednesday.at(j));
                }
            }
            total += max - min + 1;
        }

        if(taughtOnThursday.size() > 0)
        {
            min = max = schedule->getTimeFor(taughtOnThursday.at(0));
            for(unsigned j = 1; j < taughtOnThursday.size(); j++)
            {
                if(schedule->getTimeFor(taughtOnThursday.at(j)) < min)
                {
                    min = schedule->getTimeFor(taughtOnThursday.at(j));
                }
                if(schedule->getTimeFor(taughtOnThursday.at(j)) > max)
                {
                    max = schedule->getTimeFor(taughtOnThursday.at(j));
                }
            }
            total += max - min + 1;
        }

        if(taughtOnFriday.size() > 0)
        {
            min = max = schedule->getTimeFor(taughtOnFriday.at(0));
            for(unsigned j = 1; j < taughtOnFriday.size(); j++)
            {
                if(schedule->getTimeFor(taughtOnFriday.at(j)) < min)
                {
                    min = schedule->getTimeFor(taughtOnFriday.at(j));
                }
                if(schedule->getTimeFor(taughtOnFriday.at(j)) > max)
                {
                    max = schedule->getTimeFor(taughtOnFriday.at(j));
                }
            }
            total += max - min + 1;
        }
        pi.setTotalTime(total);
        double profScore = _sc(pi);
        pi.setScore(profScore);
        score += profScore;
        profInfoMap.insert(make_pair(iterator->first, pi));
    }
    schedule->setScore(score);
    return score;
}
