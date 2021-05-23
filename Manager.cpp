#include "Manager.hpp"

using namespace std;

void skip(){
	
}

void Manager::work(){
	cout << "   company task planner" << endl;
	char num='-1';
	int day=1;
	while (num!=0){
		cout << endl;
		cout << "				day"<<day;
		cout << "	Main menu\n";
		cout << "1) view database\n";
		cout << "2) find employee\n";
		cout << "3) find task\n";
		cout << "4) add manager entity\n";
		cout << "5)	edit manager entity\n";
		cout << "6) delete manager entity\n";
		cout << "7) assign task to employee\n";
		cout << "8)	pass some days\n";
		cout << endl;
		cout << "0)exit\n";
		
	cin >> num;
	switch(num){
		case '1':{
			cout << "choose the datadase\n";
			cout << "1- Employees \n 2- Tasks \n";
			int a;
			cin >> a;
			switch(a){
				case 1:{
					for (int i=0;i< basaEmp.getsize();i++){
						cout << basaEmp[i] << endl;
					}
					break;
				}
				case 2:{
					for (int i=0;i< basaTask.getsize();i++){
						cout << basaTask[i] << endl;
					}
					break;
				}
				default:{
					cout << "try again :) \n";
					break;
				}
			}
			break;
		}
		case '2':{
			cout << "enter employee's id \n";
			int code;
			cin >> code;
			for (int i=1;i<=basaEmp.getsize();i++){
				if (basaEmp[i].getEmployeeId()==code){
					cout << basaEmp[i] << endl;
				}
			}
			break;
		}
		case '3':{
			cout << "enter task's id \n";
			int code;
			cin >> code;
			for (int i=1;i<=basaTask.getsize();i++){
				if (basaTask[i].getTaskId()==code){
					cout << basaTask[i] << endl;
				}
			}
			break;
		}
		case '4':{
			cout << "choose the entity\n";
			cout << "1- Employee \n 2- Task \n";
			int a;
			cin >> a;
			switch(a){
				case 1:{
					Employee temp;
					cout << "enter the name of employee \n";
					string name;
					cin >> name;
					temp.setEmployeeName(name);
					int id(basaEmp.getsize()+1);
					temp.setEmployeeId(id);
					cout << "enter work hours \n";
					int hour;
					for (int i=0;i<7;i++){
						cin >> hour;
						temp.setEmployeeWorkingHours(i,hour);
					}
					temp.setEmployeeTask(-1);
					break;
				}
				case 2:{
					Employee temp;
					cout << "enter the name of task \n";
					string name;
					cin >> name;
					temp.setTaskName(name);
					int id(basaTask.getsize()+1);
					temp.setTaskId(id);
					cout << "enter hours for working \n";
					int hour;
					temp.setEmployeeWorkHours(i,hour);
					cout << "enter days to deadline \n";
					int days;
					cin >> days;
					temp.setTaskDeadline(hour);
					temp.setEmployeeTaskStatus(Status::toBeDone);
					break;
				}
				default:{
					cout << "try again :) \n";
					break;
				}
			}
			break;
		}
		case '5':{
			cout << "choose the entity you want to edit\n";
			cout << "1- Employee \n 2- Task \n";
			int a;
			cin >> a;
			switch(a){
				case 1:{
					cout << "enter new work hours \n";
					int hour;
					for (int i=0;i<7;i++){
						cin >> hour;
						temp.setEmployeeWorkingHours(i,hour);
					}
					break;
				}
				case 2:{
					cout << "enter days to deadline \n";
					int days;
					cin >> days;
					temp.setTaskDeadline(days);
					break;
				}
				default:{
					cout << "try again :) \n";
					break;
				}
			}
			break;
		}
		case '6':{
			cout << "choose the entity you want to delete\n";
			cout << "1- Employee \n 2- Task \n";
			int a;
			cin >> a;
			switch(a){
				case 1:{
					cout << "enter employee's id \n";
					int code;
					cin >> code;
					for (int i=1;i<=basaEmp.getsize();i++){
						if (basaEmp[i].getEmployeeId()==code){
							basaEmp.remove(basaEmp[i]);
						}
					}
					break;
				}
				case 2:{
					cout << "enter task's id \n";
					int code;
					cin >> code;
					for (int i=1;i<=basaTask.getsize();i++){
						if (basaTask[i].getTaskId()==code){
							basaTask.remove(basaTask[i]);
						}
					}
					break;
				}
				default:{
					cout << "try again :) \n";
					break;
				}
			}
			break;
		}
		case '7':{
			cout << "enter employee's id and task's id \n";
			int ecode,tcode;
			cin >> ecode >> tcode;
			for (int i=1;i<=basaEmp.getsize();i++){
				if (basaEmp[i].getEmployeeId()==ecode){
					basaEmp[i].setEmployeeTask(tcode);
					break;
				}
			}
			break;
		}
		case '8':{
			cout << "enter number of days \n";
			int d;
			cin >> d;
			for (int i=0;i<d; i++){
				skip();
			}
			break;
		}
		case '0':{
			break;
		}
		default:{
			cout << "please choose correct command \n";
		}
		}
	}
}