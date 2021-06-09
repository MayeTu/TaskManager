#include <fstream>
#include <string>
#include <iostream>

using namespace std;
/*!
  \brief Класс сотрудников

  Данный класс отображает наличие у сотридника:имени,id,количества рабочих часов в неделю и его задачи.\n
  Помимо этого,класс позволяет присвоить новое значение имени сотрудника,id сотрудника,количества рабочих часов в неделю и его задачу.
 */
class Employee
{
private:
    string employeeName;
    int employeeId;
    int employeeWorkingHours[7];
    int employeeTask;
public:
  ///Функция вывода id сотрудника.
    string getEmployeeName();
///Функция вывода id сотрудника.
    int getEmployeeId();
 ///Функция вывода количества рабочих часов в неделю.
    int getEmployeeWorkingHours(int day);
///Функция вывода задачи сотрудника.
    int getEmployeeTask();
  ///Функция присваивания имени новому сотруднику.
    void setEmployeeName(string newEmployeeName);
    ///Функция присваивания id новому сотруднику.
    void setEmployeeId(int newEmployeeId);
   ///Функция присваивания количества рабочих часов в неделю новому сотруднику.
    void setEmployeeWorkingHours(int day, int hours);
       ///Функция присваивания задачи новому сотруднику.
    void setEmployeeTask(int newEmployeeTask);
    friend ostream& operator<< (ostream &out, const Employee &it);
    friend istream& operator>> (istream &in, Employee &it);
    friend bool operator== (Employee& l, Employee& r);
};
