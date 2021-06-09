#include <vector>
#include "Employee.hpp"
#include "Task.hpp"

using namespace std;

template <typename T>
/*!
  \brief Класс работы с базой данных.

   Данный класс осуществляет функции для работы с базой данных.
 */
class Database
{
private:
    vector <T> elements;
public:
///Данная функция осуществляет загрузку базы данных из файла.
    void load (ifstream& file)
    {
        T temp;
        //cout << "fnfuif\n";
        while (file>>temp)
        {
            //cout << temp << endl;
            elements.push_back(temp);
        }
    }
///Данная функция осуществляет выгрузку базы данных из файла.
    void unload(ofstream& file)
    {
        //cout << 1;
        for (int i=0; i<elements.size(); i++)
        {
            //cout << elements[i] << endl;
            file << elements[i] << endl;
        }
    }
    T& operator[] (int i)
    {
        return elements.at(i);
    }
///Данная функция осуществляет взятия размеров массива.
    int getsize()
    {
        return elements.size();
    }
///Данная функция осуществляет удаление элемента массива.
    void remove(T elem)
    {
        for (size_t i=0; i< elements.size(); i++)
        {
            if (elements[i]==elem)
            {
                elements.erase(elements.begin()+i);
                break;
            }
        }
    }
    void add(T elem){
        elements.push_back(elem);
    }
};
