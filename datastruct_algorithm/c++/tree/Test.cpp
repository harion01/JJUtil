#include "Tree.h"

int main(){

	LCRS_Node<char> Root('A');	
	LCRS_Node<char> B('B');	
	LCRS_Node<char> C('C');	
	LCRS_Node<char> D('D');	
	LCRS_Node<char> E('E');	
	LCRS_Node<char> F('F');	
	LCRS_Node<char> G('G');	
	LCRS_Node<char> H('H');	
	LCRS_Node<char> I('I');	
	LCRS_Node<char> J('J');	
	LCRS_Node<char> K('K');	

	LCRS_Util util;
	util.LCRS_AddChildNode(&Root, &B);
		util.LCRS_AddChildNode(&B, &C);
		util.LCRS_AddChildNode(&B, &D);
			util.LCRS_AddChildNode(&D, &E);
			util.LCRS_AddChildNode(&D, &F);
	util.LCRS_AddChildNode(&Root, &G);
		util.LCRS_AddChildNode(&G, &H);
	util.LCRS_AddChildNode(&Root, &I);
		util.LCRS_AddChildNode(&I, &J);
			util.LCRS_AddChildNode(&J, &K);

	util.LCRS_PrintTree(&Root, 0);



	util.LCRS_PrintSameDepth(&Root, 0, 3);
	cout << endl;
	util.LCRS_PrintSameDepth(&Root, 0, 4);
	util.LCRS_PrintSameDepth(&Root, 0, 5);
	cout << endl;

	util.LCRS_PrintSameDepth(&Root, 0, 2);
	cout << endl;
	util.LCRS_PrintSameDepth(&Root, 0, 1);
	cout << endl;
	return 0;
}
