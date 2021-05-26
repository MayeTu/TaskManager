#include <iostream>
#include "Database.hpp"
#include "Employee.hpp"
#include "Task.hpp"

using namespace std;

class Manager{
	private:
		Database <Employee> basaEmp;
		Database <Task> basaTask;
	public:
		Manager(Database <Employee> basaEmp , Database <Task> basaTask):basaEmp(basaEmp),basaTask(basaTask){}
		void work();
		void skip();
		
};