#ifndef CPP_BTREE_H
#define CPP_BTREE_H

#include <iostream>

using namespace std;

template <typename D>
class BTREE_Util;

template <typename T>
class BTREE_Node{
	template <typename D>
	friend class BTREE_Util;
	private:
	public :
		T Data;
		class BTREE_Node<T>* Left;
		class BTREE_Node<T>* Right;

		BTREE_Node(T NewData):Data(NewData),Left(NULL),Right(NULL) {}
};

template <typename D>
class BTREE_Util{
	private:
	public:
		void PrintPreorder(BTREE_Node<D>* Root){
			if(Root == NULL){
				return;
			}

			cout << Root->Data << endl;

			PrintPreorder(Root->Left);

			PrintPreorder(Root->Right);
		}

		void PrintInorder(BTREE_Node<D>* Root){
			if(Root == NULL){
				return;
			}

			PrintInorder(Root->Left);
			
			cout << Root->Data << endl;

			PrintInorder(Root->Right);

		}

		void PrintPostorder(BTREE_Node<D>* Root){
			if(Root == NULL){
				return;
			}

			PrintPostorder(Root->Left);

			PrintPostorder(Root->Right);

			cout << Root->Data << endl;
		}

};



#endif
