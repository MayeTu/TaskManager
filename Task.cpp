#include "Task.hpp"
#include <sstream>
using namespace std;

string Task::getTaskName()
{
    return this->taskName;
}
int Task::getTaskId()
{
    return this->taskId;
}
int Task::getTaskWorkHours()
{
    return this->taskWorkHours;
}
int Task::getTaskDeadline()
{
    return this->taskDeadline;
}
Status Task::getTaskStatus()
{
    return this->taskStatus;
}
void Task::setTaskName(string newTaskName)
{
    this->taskName = newTaskName;
}
void Task::setTaskId(int newTaskId)
{
    this->taskId = newTaskId;
}
void Task::setTaskWorkHours(int day)
{
    this->taskWorkHours = day;
}
void Task::setTaskDeadline(int day)
{
    this->taskDeadline = day;
}
void Task::setTaskStatus(Status newTaskStatus)
{
    this->taskStatus = newTaskStatus;
}

ostream& operator<< (ostream& out, const Task& it)
{
    out<< it.taskName <<'\n'<< it.taskId << ' ' << it.taskWorkHours << ' ' << it.taskDeadline << '\n';
    if (it.taskStatus==Status::ToBeDone)
    {
        out<<"ToBeDone";
    }
    if (it.taskStatus==Status::Failed)
    {
        out<< "Failed";
    }
    if (it.taskStatus==Status::Done)
    {
        out<<"Done";
    }
    if (it.taskStatus==Status::Working)
    {
        out<<"Working";
    }
    return out;
}

istream& operator>> (istream& in, Task& it)
{
    getline(in,it.taskName);
    string s;
    getline(in,s);
    stringstream ss(s);
    ss>>it.taskId >> it.taskWorkHours >> it.taskDeadline;
    getline(in,s);
    if (s=="ToBeDone")
    {
        it.taskStatus=Status::ToBeDone;
    }
    if (s=="Failed")
    {
        it.taskStatus=Status::Failed;
    }
    if (s=="Done")
    {
        it.taskStatus=Status::Done;
    }
    if (s=="Working")
    {
        it.taskStatus=Status::Working;
    }
    return in;
}

bool Task::operator==(Task& r)
{
    if (this->taskName == r.taskName && this->taskId == r.taskId && this->taskWorkHours == r.taskWorkHours && this->taskDeadline == r.taskDeadline && this->taskStatus == r.taskStatus) return true;
    return false;
}
