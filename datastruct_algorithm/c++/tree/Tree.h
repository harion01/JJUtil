#ifndef LCRS_CPPT_TREE_H
#define LCRS_CPPT_TREE_H

#include <iostream>

using namespace std;

class LCRS_Util;

template <typename T>
class LCRS_Node{
	friend class LCRS_Util;
	private:
		T Data;
		class LCRS_Node<T>* LeftChild;
		class LCRS_Node<T>* RightSibling;

	public:
		LCRS_Node(T NewData): Data(NewData), LeftChild(NULL), RightSibling(NULL){
		}
};



class LCRS_Util{
	private:
	public:
		void LCRS_AddChildNode(LCRS_Node<char>* Parent, LCRS_Node<char>* Child);
		void LCRS_PrintTree(LCRS_Node<char>* Node, int Depth);
		void LCRS_PrintSameDepth(LCRS_Node<char>* Node, int currDepth, int TargetDepth);
};

#endif
