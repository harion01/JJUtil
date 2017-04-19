#include "Tree.h"

void LCRS_Util::LCRS_AddChildNode(LCRS_Node<char>* Parent, LCRS_Node<char>* Child){
	if(Parent->LeftChild == NULL){
		//cout << "add LC" << endl;
		Parent->LeftChild = Child;
		return;
	}
	
	LCRS_Node<char>* imsi;
	imsi = Parent->LeftChild;
	while(imsi->RightSibling != NULL){
		//cout << "move 1";
		imsi = imsi->RightSibling;
	}
	//cout << "add ->RS" << endl;
	imsi->RightSibling = Child;
}


void LCRS_Util::LCRS_PrintTree(LCRS_Node<char>* Node, int Depth){
	
	for(int i=0; i<Depth; i++){
		cout << "  " ;
	}
	cout << Node->Data << " :  Curr [" << (Node) << " " <<
		"] L [" <<(Node->LeftChild) << 
		"] R [" << (Node->RightSibling) << "]" << endl;

	if(Node->LeftChild !=NULL){
		LCRS_Util::LCRS_PrintTree(Node->LeftChild, Depth +1);
	}

	if(Node->RightSibling!=NULL){
		LCRS_Util::LCRS_PrintTree(Node->RightSibling, Depth );
	}

}


void LCRS_Util::LCRS_PrintSameDepth(LCRS_Node<char>* Node, int currDepth, int TargetDepth){
	if(currDepth < TargetDepth){
		if(Node->LeftChild !=NULL){
			LCRS_Util::LCRS_PrintSameDepth(Node->LeftChild, currDepth+1, TargetDepth);
		}

		if(Node->RightSibling!=NULL){
			LCRS_Util::LCRS_PrintSameDepth(Node->RightSibling, currDepth, TargetDepth );
		}
	}else if ( currDepth > TargetDepth){
		cout << "Search fail! We can't reach parent node" << endl;
	}else{
		cout << Node->Data << " Depth ["<<currDepth<<"] :  Curr [" << (Node) << " " <<
		"] L [" <<(Node->LeftChild) << 
		"] R [" << (Node->RightSibling) << "]" << endl;
		if(Node->RightSibling!=NULL){
			LCRS_Util::LCRS_PrintSameDepth(Node->RightSibling, currDepth, TargetDepth);	
		}
	}
}


