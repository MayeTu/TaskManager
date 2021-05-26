#include <vector>

using namespace std;

Template <typename T>

Database{
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
			for (int i=0; i< elements.size[i];i++){
				if (elemets[i]==elem){
					elemets.erase(i);
					break;
				}
			}
		}
};