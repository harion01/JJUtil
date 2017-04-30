#include "DisjointSet.h"

/*
struct DisjointSet{
	public:
		struct DisjointSet* Parent;
		void* Data;
};
*/

DisjointSet* DisjointUtil::DS_FindRoot(DisjointSet* Set){
	while(Set->Parent !=NULL){
		Set = Set->Parent;
	}

	return Set;
}

DisjointSet* DisjointUtil::MakeSet(void* NewData){
	DisjointSet* Set = new DisjointSet();
	Set->Parent = NULL;
	Set->Data = NewData;
	return Set;
}

void DisjointUtil::DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2){
	DisjointSet* Root = DS_FindRoot(Set2);
	Root->Parent = Set1;
}



#endif
