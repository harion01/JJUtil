#include <stdio.h>

int main(){
	const int a = 12345; //cont makes a into constant value. 
//	a = 2;  - constant value can not be changed after define. (like 1 =2  );


	int c = 3;
	int d = 4;
	const int* b; //can not change the value of b;
	b = &c;  //const int* b = memory address of c
//	*b = 10;  - value of b can not  be changed
	printf("b:%d\n", *b);
	b = &d; //address can be changed
	printf("b:%d\n", *b);

	
	int e = 5;
	int* const f = &e; //can not change the address of f
	//f = &e; -cannot value address(int*) of f
	*f = 10;
	printf("f:%d\n", *f);

	int z = 100;
	int x = 200;
	const int* const g = &z;
//	g = &x ; -cannot change address of g
//	*g = 200; -cannot change value of g

	printf("z:%d\n", *g);

	return 0;
}
