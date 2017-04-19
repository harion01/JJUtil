#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class PersonName{
	public:
		string name;
		int age;
		PersonName(string name, int age) : name(name), age(age) {}

		bool operator <(const PersonName &a)const {
			return this->age < a.age;
		}
};




int main(){

	vector<PersonName> v1;
	v1.push_back(PersonName("AA", 22));
	v1.push_back(PersonName("BB", 25));
	v1.push_back(PersonName("BC", 33));
	v1.push_back(PersonName("AD", 44));

	sort(v1.begin(), v1.end());
	for( int i = 0; i < v1.size(); i++){
		cout << v1[i].age << ", " << v1[i].name << endl;
	}
}
