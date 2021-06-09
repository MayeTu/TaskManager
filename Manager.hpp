#include <iostream>
#include "Database.hpp"

using namespace std;
/*!
 * \brief Класс присваивания

 Данный класс обьявляет объекты для классов Employee и Task.\n
 Также этот класс объявляет функции work и skip.
 */
class Manager
{
private:
    Database <Employee> &basaEmp;
    Database <Task> &basaTask;
    int day;
public:
    Manager(Database <Employee> &basaEmp, Database <Task> &basaTask):basaEmp(basaEmp),basaTask(basaTask) {}
    void work();
    void skip();

};
