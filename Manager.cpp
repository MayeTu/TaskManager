#include "Manager.hpp"

using namespace std;

void Manager::skip()
{
    for (int i=0; i<basaEmp.getsize(); i++)
    {
        if (basaEmp[i].getEmployeeTask() != -1)
        {
            int code=basaEmp[i].getEmployeeTask();
            for (int j=0 ; j < basaTask.getsize() ; j++)
            {
                if (basaTask[j].getTaskId()==code)
                {
                    basaTask[j].setTaskWorkHours(basaTask[j].getTaskWorkHours()-basaEmp[i].getEmployeeWorkingHours(day%7));
                    break;
                }
            }
        }
    }
    for (int i=0; i<basaTask.getsize(); i++)
    {
        if (basaTask[i].getTaskStatus()==Status::ToBeDone || basaTask[i].getTaskStatus()==Status::Working){
            basaTask[i].setTaskDeadline(basaTask[i].getTaskDeadline()-1);
        }
        if (basaTask[i].getTaskWorkHours()<1)
        {
            basaTask[i].setTaskStatus(Status::Done);
            for (int i=0; i<basaEmp.getsize(); i++)
            {
                if (basaEmp[i].getEmployeeTask() == basaTask[i].getTaskId())
                {
                    basaEmp[i].setEmployeeTask(-1);
                }
            }
        }
        if (basaTask[i].getTaskDeadline() == 0 && basaTask[i].getTaskWorkHours()>0 && basaTask[i].getTaskStatus() !=Status::Failed )
        {
            basaTask[i].setTaskStatus(Status::Failed);
        }
        if (basaTask[i].getTaskDeadline() < 0){
            basaTask[i].setTaskDeadline(0);
        }
        if (basaTask[i].getTaskWorkHours() < 0 || basaTask[i].getTaskStatus() == Status::Done){
            basaTask[i].setTaskWorkHours(-1);
            basaTask[i].setTaskDeadline(0);
        }

    }
    day++;
}

void Manager::work()
{
    cout << "   company task planner" << endl;
    char num{};
    int day=0;
    while (num!='0')
    {
        cout << endl;
        cout << "				day "<<day;
        cout << "                  \n";
        cout << "	Main menu\n";
        cout << "1) view database\n";
        cout << "2) find employee\n";
        cout << "3) find task\n";
        cout << "4) add manager entity\n";
        cout << "5) edit manager entity\n";
        cout << "6) delete manager entity\n";
        cout << "7) assign task to employee\n";
        cout << "8) pass some days\n";
        cout << endl;
        cout << "0)exit\n";

        cin >> num;
        switch(num)
        {
        case '1':
        {
            cout << "choose the datadase\n";
            cout << "1- Employees \n2- Tasks \n";
            int a;
            cin >> a;
            switch(a)
            {
            case 1:
            {
                for (int i=0; i< basaEmp.getsize(); i++)
                {
                    cout << basaEmp[i] << endl;
                }
                break;
            }
            case 2:
            {
                for (int i=0; i< basaTask.getsize(); i++)
                {
                    cout << basaTask[i] << endl;
                }
                break;
            }
            default:
            {
                cout << "try again :) \n";
                break;
            }
            }
            break;
        }
        case '2':
        {
            cout << "enter employee's id \n";
            int code,k;
            k=0;
            cin >> code;
            for (int i=0; i<basaEmp.getsize(); i++)
            {
                if (basaEmp[i].getEmployeeId()==code)
                {
                    cout << basaEmp[i] << endl;
                    k=1;
                    break;
                }
            }
            if (k==0){
                cout << "   there is no such person \n" ;
            }
            break;
        }
        case '3':
        {
            cout << "enter task's id \n";
            int code,k;
            k=0;
            cin >> code;
            for (int i=0; i<basaTask.getsize(); i++)
            {
                if (basaTask[i].getTaskId()==code)
                {
                    cout << basaTask[i] << endl;
                    k=1;
                    break;
                }
            }
            if (k==0){
                cout << "   there is no such person \n" ;
            }
            break;
        }
        case '4':
        {
            cout << "choose the entity\n";
            cout << "1- Employee \n2- Task \n";
            int a;
            cin >> a;
            switch(a)
            {
            case 1:
            {
                Employee temp;
                cout << "enter the name of employee \n";
                string name;
                getline(cin,name);
                getline(cin,name);
                temp.setEmployeeName(name);
                int id(basaEmp.getsize()+1);
                temp.setEmployeeId(id);
                cout << "enter work hours \n";
                int hour;
                for (int i=0; i<7; i++)
                {
                    cin >> hour;
                    temp.setEmployeeWorkingHours(i,hour);
                }
                temp.setEmployeeTask(-1);
                basaEmp.add(temp);
                break;
            }
            case 2:
            {
                Task temp;
                cout << "enter the name of task \n";
                string name;
                getline(cin,name);
                getline(cin,name);
                temp.setTaskName(name);
                int id(basaTask.getsize()+1);
                temp.setTaskId(id);
                cout << "enter hours for working \n";
                int hour;
                cin >> hour;
                temp.setTaskWorkHours(hour);
                cout << "enter days to deadline \n";
                int days;
                cin >> days;
                temp.setTaskDeadline(days);
                temp.setTaskStatus(Status::ToBeDone);
                basaTask.add(temp);
                break;
            }
            default:
            {
                cout << "try again :) \n";
                break;
            }
            }
            break;
        }
        case '5':
        {
            cout << "choose the entity you want to edit\n";
            cout << "1- Employee \n2- Task \n";
            int a;
            cin >> a;
            switch(a)
            {
            case 1:
            {
                cout << "employee's id \n";
                int code;
                cin >> code;
                Employee *temp;
                for (int i=0; i<basaEmp.getsize(); i++)
                {
                    if (basaEmp[i].getEmployeeId()==code)
                    {
                        temp=&basaEmp[i];
                        break;
                    }
                }
                cout << "enter new work hours \n";
                int hour;
                for (int i=0; i<7; i++)
                {
                    cin >> hour;
                    temp->setEmployeeWorkingHours(i,hour);
                }
                break;
            }
            case 2:
            {
                cout << "task's id \n";
                int code;
                cin >> code;
                Task *temp;
                for (int i=0; i<basaTask.getsize(); i++)
                {
                    if (basaTask[i].getTaskId()==code)
                    {
                        temp=&basaTask[i];
                    }
                }
                cout << "enter days to deadline \n";
                int days;
                cin >> days;
                temp->setTaskDeadline(days);
                break;
            }
            default:
            {
                cout << "try again :) \n";
                break;
            }
            }
            break;
        }
        case '6':
        {
            cout << "choose the entity you want to delete\n";
            cout << "1- Employee \n2- Task \n";
            int a;
            cin >> a;
            switch(a)
            {
            case 1:
            {
                cout << "enter employee's id \n";
                int code;
                cin >> code;
                for (int i=0; i<basaEmp.getsize(); i++)
                {
                    if (basaEmp[i].getEmployeeId()==code)
                    {
                        basaEmp.remove(basaEmp[i]);
                    }
                }
                break;
            }
            case 2:
            {
                cout << "enter task's id \n";
                int code;
                cin >> code;
                for (int i=0; i<basaTask.getsize(); i++)
                {
                    if (basaTask[i].getTaskId()==code)
                    {
						basaTask.remove(basaTask[i]);
                    }
                }
				for (int i=0; i<basaEmp.getsize(); i++)
                {
                    if (basaEmp[i].getEmployeeTask()==code)
                    {
                        basaEmp[i].setEmployeeTask(-1);
                    }
                }
                break;
            }
            default:
            {
                cout << "try again :) \n";
                break;
            }
            }
            break;
        }
        case '7':
        {
            cout << "enter employee's id and task's id \n";
            int ecode,tcode;
            cin >> ecode >> tcode;
            for (int i=0; i<basaEmp.getsize(); i++)
            {
                //cout << "0000";
                if (basaEmp[i].getEmployeeId()==ecode)
                {
                    //cout << 111;
                    basaEmp[i].setEmployeeTask(tcode);
                    basaTask[i].setTaskStatus(Status::Working);
                    break;
                }
            }
            break;
        }
        case '8':
        {
            cout << "enter number of days \n";
            int d;
            cin >> d;
            for (int i=0; i<d; i++)
            {
                skip();
            }
            day+=d;
            break;
        }
        case '0':
        {
            cout << "have a good day \n";
            return;
        }
        default:
        {
            cout << "please choose correct command \n";
        }
        }
    }
}
