#include <vector>
#include "Employee.hpp"
#include "Task.hpp"

using namespace std;

template <typename T>

class Database
{
private:
    vector <T> elements;
public:
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
    int getsize()
    {
        return elements.size();
    }
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
