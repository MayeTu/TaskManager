#include <iostream>
#include "Database.hpp"

using namespace std;

class Manager{
	private:
		Database <Employee> basaEmp;
		Database <Task> basaTask;
		int day;
	public:
		Manager(Database <Employee> basaEmp , Database <Task> basaTask):basaEmp(basaEmp),basaTask(basaTask){}
		void work();
		void skip();

};
