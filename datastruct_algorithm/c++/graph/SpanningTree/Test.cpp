#include "MinST.h"


int main(void){
	Graph test(9);
	//test.MakePrimMST(1);

	test.addEdge(0,1,35);
	test.addEdge(0,4,247);

	test.addEdge(1,0,35);
	test.addEdge(1,2,126);
	test.addEdge(1,5,150);

	test.addEdge(2,1,126);
	test.addEdge(2,3,117);
	test.addEdge(2,5,162);
	test.addEdge(2,6,220);

	test.addEdge(3,2,117);

	test.addEdge(4,0,247);
	test.addEdge(4,5,82);
	test.addEdge(4,7,98);

	test.addEdge(5,1,150);
	test.addEdge(5,2,162);
	test.addEdge(5,4,82);
	test.addEdge(5,6,154);
	test.addEdge(5,7,120);

	test.addEdge(6,2,220);
	test.addEdge(6,5,154);
	test.addEdge(6,8,106);

	test.addEdge(7,4,98);
	test.addEdge(7,5,120);

	test.addEdge(8,6,106);

	test.printVertex();

	cout << endl;
	cout << endl;
	cout << endl;

	test.MakePrimMST(1);



	cout << endl;
	cout << endl;
	cout << endl;
	test.printMST();
	
	return 0;
}
