#ifndef LCRS_CPPT_TREE_H
#define LCRS_CPPT_TREE_H

#include <iostream>

using namespace std;

template <typename Z>
class LCRS_Util;

template <typename T>
class LCRS_Node{
	template <typename Z>
	friend class LCRS_Util;
	private:
		

		T Data;
		class LCRS_Node<T>* LeftChild;
		class LCRS_Node<T>* RightSibling;

	public:
		LCRS_Node(T NewData): Data(NewData), LeftChild(NULL), RightSibling(NULL){
		}
};


template <typename Z>
class LCRS_Util{
	private:
	public:
		void LCRS_AddChildNode(LCRS_Node<Z>* Parent, LCRS_Node<Z>* Child)
		{

			if(Parent->LeftChild == NULL){
				//cout << "add LC" << endl;
				Parent->LeftChild = Child;
				return;
			}

			LCRS_Node<Z>* imsi;
			imsi = Parent->LeftChild;
			while(imsi->RightSibling != NULL){
				//cout << "move 1";
				imsi = imsi->RightSibling;
			}
			//cout << "add ->RS" << endl;
			imsi->RightSibling = Child;
		}

};

#endif
