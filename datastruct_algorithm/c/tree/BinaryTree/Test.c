#include "SimpleBinaryTree.h"

int main(){
	
	SBTNode* A = SBT_CreateNode('A');
	SBTNode* B = SBT_CreateNode('B');
	SBTNode* C = SBT_CreateNode('C');
	SBTNode* D = SBT_CreateNode('D');
	SBTNode* E = SBT_CreateNode('E');
	SBTNode* F = SBT_CreateNode('F');
	SBTNode* G = SBT_CreateNode('G');

	SBTNode* Z = SBT_CreateNode('Z');
	SBTNode* X = SBT_CreateNode('X');

	
	A->Left = B;
	B->Left = C;
	B->Right = D;

	D->Left = Z;
	D->Right = X;

	A->Right = E;
	E->Left = F;
	E->Right = G;

	
	printf("=== preorder ===\n");
	SBT_PrintPreorderTree(A);
	printf("\n\n");

	printf("=== ineorder ===\n");
	SBT_PrintInorderTree(A);
	printf("\n\n");

	printf("=== postorder ===\n");
	SBT_PrintPostorderTree(A);
	printf("\n\n");
	return 0;
}
