#include <stdio.h>

typedef enum {
	a=10,
	b,
	c=4,
	d,
	e,
	f=1,
	g,
	h = 'a',
	i
}test;

int main(void){
	test VAL;
	
	
	printf("enum test\n");
	printf("a : %d\n",a);
	printf("b : %d\n",b);
	printf("c : %d\n",c);
	printf("d : %d\n",d);
	printf("e : %d\n",e);
	printf("f : %d\n",f);
	printf("g : %d\n",g);
	printf("h : %d %c\n",h,h);
	printf("i : %d %c\n",i,i);


	
	return 0;
}

