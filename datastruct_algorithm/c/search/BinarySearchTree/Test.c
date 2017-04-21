#include "BinarySearchTree.h"

int main(){
	BSTNode* Tree = BST_CreateNode(123);
	BSTNode* Node = NULL;

	BST_InsertNode(Tree, BST_CreateNode(22) );
	BST_InsertNode(Tree, BST_CreateNode(9918) );
	BST_InsertNode(Tree, BST_CreateNode(424) );
	BST_InsertNode(Tree, BST_CreateNode(17) );
	BST_InsertNode(Tree, BST_CreateNode(3) );

	BST_InsertNode(Tree, BST_CreateNode(98) );
	BST_InsertNode(Tree, BST_CreateNode(34) );

	BST_InsertNode(Tree, BST_CreateNode(760) );
	BST_InsertNode(Tree, BST_CreateNode(317) );
	BST_InsertNode(Tree, BST_CreateNode(1) );

	BST_InorderPrintTree(Tree);
	printf("\n");

	printf("Remove 98\n");
	Node = BST_RemoveNode(Tree, NULL, 98);
	BST_DestroyTree(Node);

	BST_InorderPrintTree(Tree);
	printf("\n");

	printf("Insert 111 \n");
	BST_InsertNode(Tree, BST_CreateNode(111));
	BST_InorderPrintTree(Tree);
	printf("\n");

	BST_DestroyTree(Tree);


	return 0;
}
