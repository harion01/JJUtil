#include "JJCalc.h"

int main (){
	JJcalc JJ;
	string exp = "1+3.334/(4.28*(110-7729))";
	cout << "and : [" << JJ.Calculate(exp) <<"]"<< endl;

	return 0;
}
