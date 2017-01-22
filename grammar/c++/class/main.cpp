#include "class.h"

int main(){
	//Chulsoo chulsoo= {"chulsoo", "male" , "writter", "deligent", 32, true};
	//Younghee younghee = {"younghee", "female" , "housewife", "impatient", 32, true};
	
	Chulsoo chulsoo("chulsoo", "male" , "writter", "deligent", 32, true);
	Younghee younghee("younghee", "female" , "housewife", "impatient", 32, true);

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
