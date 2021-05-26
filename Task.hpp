#include <fstream>
#include <string>
#include <iostream>

using namespace std;

enum class Status{
	ToBeDone,
	Working,
	Failed,
	Done
};

class Task;
{
private:
    string taskName;
    int taskId;
	int taskWorkHours;
	int taskDeadline;
	Status taskStatus();
public:
    string getTaskName();
    int getTaskId();
	int getTaskWorkHours(int day);
	int getDeadline();
	Status getTaskStatus();
    void setTask Name(string newTaskName);
    void setTaskId(int newTaskId);
	void setTaskWorkHours(int day);
	void setTaskDadline(int days);
	void setTaskStatus(int newTaskStatus);
    friend ostream& operator<< (ostream &out, const Task &it);
    friend istream& operator>> (istream &in, Task &it);
    bool operator== (Task& r);
};