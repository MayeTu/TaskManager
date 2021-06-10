#include <fstream>
#include <string>
#include <iostream>

using namespace std;

enum class Status
{
    ToBeDone,
    Working,
    Failed,
    Done
};
/*!
 *  \brief Класс задач для сотрудников.
 *
 *  Класс Task отвечает за объявление функций для манипуляций задачами сотрудников.
 */
class Task
{
private:
    string taskName;
    int taskId;
    int taskWorkHours;
    int taskDeadline;
    Status taskStatus;
public:
    ///Данная функция отвечает за вывод имени у задачи.
    string getTaskName();
    ///Данная функция отвечает за вывод id у задачи.
    int getTaskId();
    ///Данная функция отвечает за вывод количества рабочих часов у задачи.
    int getTaskWorkHours();
       ///Данная функция отвечает за вывод оставшегося времени до сдачи задания.
    int getTaskDeadline();
        ///Данная функция отвечает за вывод статуса выполнения задачи сотрудником.
    Status getTaskStatus();
        ///Данная функция отвечает за присваивания имени новой задаче.
    void setTaskName(string newTaskName);
    ///Данная функция отвечает за присваивание id новой задаче.
    void setTaskId(int newTaskId);
    ///Данная функция отвечает за присваивание количества рабочих часов для новой задачи.
    void setTaskWorkHours(int day);
        ///Данная функция отвечает за присваивание количества оставшихся дней до сдачи задания.
    void setTaskDeadline(int days);
        ///Данная функция отвечает за присваивание статуса выполнения для новой задачи.
    void setTaskStatus(Status newTaskStatus);
    friend ostream& operator<< (ostream &out, const Task &it);
    friend istream& operator>> (istream &in, Task &it);
    bool operator== (Task& r);
};
