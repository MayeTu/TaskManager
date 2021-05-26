#include <vector>
#include "Employee.hpp"
#include "Task.hpp"

using namespace std;

template <typename T>

class Database{
	private:
		vector <T> elements;
	public:
		void load (ifstream& file){
			T temp;
			while (file>>temp){
				elements.push_back(temp);
			}
		}
		void unload(ofstream& file){
			for (int i=0; i<elements.size();i++){
					file << elements[i] << endl;
			}
		}
		T operator[] (int i){
			return elements.at(i);
		}
		int getsize(){
			return elements.size();
		}
		void remove(T elem){
			for (int i=0; i< elements.size();i++){
				if (elements[i]==elem){
					elements.erase(elements.begin()+i);
					break;
				}
			}
		}
};
