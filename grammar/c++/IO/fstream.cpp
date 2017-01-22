#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){
	string str = "test is test";
	ofstream ofs("file.txt"); //open file
	ofs << str; //write file.txt
	ofs.close();
	ifstream ifs("file.txt");
	ifs >> str;
	cout << str << endl;
	ifs.close();

	return 0;
}
