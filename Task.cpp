#include "Task.hpp"
using namespace std;

string Task::getTaskName() {
	return this->taskName;
}
int Task::getTaskId() {
	return this->taskId;
}
int Task::getTaskWorkHours() {
	return this->taskWorkHours;
}
int Task::getTaskDeadline() {
	return this->taskDeadline;
}
Status Task::getTaskStatus() {
///	return this->taskStatus;
}
void Task::setTaskName(string newTaskName) {
	this->taskName = newTaskName;
}
void Task::setTaskId(int newTaskId) {
	this->taskId = newTaskId;
}
void Task::setTaskWorkHours(int day) {
	this->taskWorkHours = day;
}
void Task::setTaskDeadline(int day) {
	this->taskDeadline = day;
}
void Task::setTaskStatus(Status newTaskStatus) {
	this->taskStatus = newTaskStatus;
}

ostream& operator<< (ostream& out, const Task& it) {
	out<< it.taskName <<' '<< it.taskId << ' ' << it.taskWorkHours << it.taskDeadline << ' ' << static_cast<int>(it.taskStatus)<<'\n';
	return out;
}

istream& operator>> (istream& in, Task& it) {
	in >> it.taskName >> it.taskId >> it.taskWorkHours >> it.taskDeadline;
	int s;
	in >> s;
	it.taskStatus = static_cast<Status>(s);
	return in;
}

bool Task::operator==(Task& r) {
	if (this->taskName == r.taskName && this->taskId == r.taskId && this->taskWorkHours == r.taskWorkHours && this->taskDeadline == r.taskDeadline && this->taskStatus == r.taskStatus) return true;
	return false;
}
