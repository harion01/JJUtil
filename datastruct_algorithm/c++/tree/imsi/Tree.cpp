#include "Tree.h"

/*
template <typename T>
void LCRS_Util<T>::LCRS_AddChildNode(LCRS_Node<T>* Parent,LCRS_Node<T>* Child){

	if(Parent->LeftChild == NULL){
		//cout << "add LC" << endl;
		Parent->LeftChild = Child;
		return;
	}
	
	LCRS_Node<T>* imsi;
	imsi = Parent->LeftChild;
	while(imsi->RightSibling != NULL){
		//cout << "move 1";
		imsi = imsi->RightSibling;
	}
	//cout << "add ->RS" << endl;
	imsi->RightSibling = Child;
}
*/
