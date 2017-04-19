#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person{
	public:
		string name;
		int age;

		Person(string name, int age): name(name),age(age) {}
};

bool comp(const Person &a, const Person &b){
	return a.name < b.name;
}

int main(){
	vector<Person> v;
	v.push_back(Person("aa", 22));
	v.push_back(Person("ab", 90));
	v.push_back(Person("ba", 80));
	v.push_back(Person("ca", 70));
	sort(v.begin(), v.end(), comp);

	for(int i=0; i < v.size(); i++){
		cout << v[i].age << ", " << v[i].name << endl;

	}

	return 0;
}
