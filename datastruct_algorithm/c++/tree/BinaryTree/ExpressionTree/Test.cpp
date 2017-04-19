#include "ExpressionTree.h"

using namespace std;

int main(){
	string EXP = "7 1 * 5 2 - /";
	EXPBtree Test(EXP);
	Test.PrintPreOrder();
	Test.PrintInOrder();
	Test.PrintPostOrder();

	cout << "result : " << Test.GetAnswer() << endl;
	
	return 0;
}
