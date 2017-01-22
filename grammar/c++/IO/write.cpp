#include <fstream>

using namespace std;
int main(){
	ofstream ofs;
	ofs.open("file.txt");
	ofs.write("this is an apple", 16);
	long pos = ofs.tellp();

	ofs.seekp(pos-7);
	ofs.write( " sam",4);
	ofs.close();
	return 0;
}
