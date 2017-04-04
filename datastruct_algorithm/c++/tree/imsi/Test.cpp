#include "Tree.h"

int main(){

	LCRS_Node<char> Root('A');	
	LCRS_Node<char> B('B');	

	LCRS_Util<char> util;
	util.LCRS_AddChildNode(&Root, &B);
	return 0;
}
