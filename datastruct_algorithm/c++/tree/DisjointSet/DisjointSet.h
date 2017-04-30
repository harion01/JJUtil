#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

struct DisjointSet{
	public:
		struct DisjointSet* Parent;
		void* Data;
};

class DisjointUtil{
	public:
		DisjointSet* DS_FindRoot(DisjointSet* Set);
		DisjointSet* MakeSet(void* NewData);
		void DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2);
}



#endif
