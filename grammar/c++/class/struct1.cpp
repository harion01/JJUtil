#include <iostream>
using namespace std;

#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 20
#define CHARACTER_LEN 20

struct Chulsoo{
	char name[NAME_LEN];
	char sex[SEX_LEN];
	char job[JOB_LEN];
	char character[CHARACTER_LEN];
	int age;
	bool marriageStatus;

	void introduce(){
		cout << "name : " << name << endl;
		cout << "sex  : " << sex << endl;
		cout << "job  : " << job << endl;
		cout << "character : " << character << endl;
		cout << "age : " << age << endl;
		cout << "marriage status : " << (marriageStatus ? "Yes" : "NO") << endl;
	}

	void eat(char* food){
		cout << "chulsoo eat [" << food << "]" << endl;
	}
	
	void sleep(){
		cout << "chulsoo sleep" << endl;
	}

	void drive(char* destination ){
		cout << "chulsoo drive to [" << destination << "]" << endl;
	}

	void write(){
		cout << "chulsoo write a book" << endl;
	}

	void read(){
		cout << "chulsoo read a book" << endl;
	}
};


struct Younghee{
	char name[NAME_LEN];
	char sex[SEX_LEN];
	char job[JOB_LEN];
	char character[CHARACTER_LEN];
	int age;
	bool marriageStatus;

	void introduce(){
		cout << "name : " << name << endl;
		cout << "sex  : " << sex << endl;
		cout << "job  : " << job << endl;
		cout << "character : " << character << endl;
		cout << "age : " << age << endl;
		cout << "marriage status : " << (marriageStatus ? "Yes" : "NO") << endl;
	}

	void eat(char* food){
		cout << "Younghee eat [" << food << "]" << endl;
	}
	
	void sleep(){
		cout << "Younghee sleep" << endl;
	}

	void shopping(){
		cout << "Younghee shopping" << endl;
	}
};

int main(){
	Chulsoo chulsoo = {"chulsoo", "male" , "writter", "deligent", 32, true};
	Younghee younghee = {"younghee", "female" , "housewife", "impatient", 32, true};
	
	chulsoo.drive("restaurant");
	chulsoo.eat("steak");
	younghee.eat("steak");
	chulsoo.drive("house");
	younghee.sleep();
	chulsoo.write();
	chulsoo.read();
	chulsoo.sleep();
	cout << endl;

	chulsoo.introduce();
	cout << endl;
	younghee.introduce();

	return 0;

	return 0;
}
