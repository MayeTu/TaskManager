#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Manager.hpp"

using namespace std;

//void opening(ifstream& file, string filename, int n)//функция для проверки на открытие файлов с бд
//{
//	//ifstream file;
//	file.open(filename);
//	if (!file.is_open())//если не открылся файл то выхоим с программы
//	{
//		cout << "   !!!   THE DATABASE NUMBER " << n << " IS BROKEN   !!!   " << endl;
//		//return 0;
//	}
//}

int main(int argc, char* argv[]){
	// argv[1] ---> Employee; argv[2] ---> Task
	if (argc!=3) //проверка на количество аргументов
	{ 
			cout << "   !!!   PLEASE, PROVIDE EXACTLY 2 DATABASE FILENAMES  !!!   " << endl;
			return 0;
	}
	
	//string employeeName=argv[1]; // переносим название бд в переменные
	//string taskName=argv[2];
	//ifstream file1;
	//ifstream file2;
	//opening(file1, employeeName, 1);// открываем файлы с бд
	//opening(file2, taskName, 2);

	ifstream file1;
	ifstream file2;
	file1.open(argv[1]);
	file2.open(argv[2]);
	if (!file1.is_open() || !file2.is_open())//если не открылся файл то выходим с программы
	{
		//cout << "   !!!   THE DATABASE NUMBER " << n << " IS BROKEN   !!!   " << endl;
		cout << "   !!!   THE DATABASE IS BROKEN OR DOES NOT EXIST   !!!   " << endl;
	}

	
	Database <Employee> basa1;// загружаем бд в оперативную память и закрываем тектовые файлы
	Database <Task> basa2;
	basa1.load(file1);
	basa2.load(file2);
	file1.close();
	file2.close();
	
	Manager manager(basa1, basa2);
	manager.work();// запускаем работу менеджера 
	
	ofstream file11; //обновляем текстовые файлы бд и закрываем их
	ofstream file22;
	//opening(file11, employeeName, 1);
	//opening(file22, taskName, 2);

	file11.open(argv[1]);
	file22.open(argv[2]);
	
	basa1.unload(file11);
	file11.close();
	basa2.unload(file22);
	file22.close();
	
	return 0;
}}
