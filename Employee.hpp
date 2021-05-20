#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Employee
{
private:
    string employeeName;
    int employeeId;
	int employeeWorkingHours[7];
	int employeeTask;
public:
    string getEmployeeName();
    int getEmployeeId();
	int getEmployeeWorkingHours(int day);
	int getEmployeeTask();
    void setEmployeeName(string newEmployeeName);
    void setEmployeeId(int newEmployeeId);
	void setEmployeeWorkingHours(int day);
	void setEmployeeTask(int newEmployeeTask);
    friend ostream& operator<< (ostream &out, const Employee &it);
    friend istream& operator>> (istream &in, Employee &it);
    bool operator== (Employee& r);
};