#include "Employee.hpp"
using namespace std;

string Employee::getEmployeeName() {
	return employeeName;
}

int Employee::getEmployeeId() {
	return employeeId;
}

int Employee::getEmployeeWorkingHours(int day) {
	return employeeWorkingHours[day];
}

int Employee::getEmployeeTask() {
	return employeeTask;
}

void Employee::setEmployeeName(string newEmployeeName) {
	this->employeeName = newEmployeeName;
}

void Employee::setEmployeeId(int newEmployeeId) {
	this->employeeId = newEmployeeId;
}

void Employee::setEmployeeWorkingHours(int day, int hours) {
	this->employeeWorkingHours[day] = hours;
}

void Employee::setEmployeeTask(int newEmployeeTask) {
	this->employeeTask = newEmployeeTask;
}

ostream& operator<< (ostream& out, const Employee& it) {
	out << it.employeeName << endl << it.employeeId << " ";
	for (int i = 0; i < 7; i++) {
		out << it.employeeWorkingHours[i] << " ";
	}
	out << it.employeeTask << endl;
	return out;
}

istream& operator>> (istream& in, Employee& it) {
	in >> it.employeeName>> it.employeeId;
	for (int i = 0; i < 7; i++) {
		in >> it.employeeWorkingHours[i];
	}
	in >> it.employeeTask;
	return in;
}

bool operator== (Employee& l, Employee& r) {
	bool check = true;
	for (int i = 0; i < 7; i++) {
		if (l.employeeWorkingHours[i] != r.employeeWorkingHours[i]) {
			check = false;
			break;
		}
	}
	return l.employeeId == r.employeeId &&
		l.employeeName == r.employeeName &&
		l.employeeTask == r.employeeTask &&
		check;

}
