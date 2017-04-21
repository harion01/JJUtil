#include <stdio.h>

int main(){
	/*
signed char: -2^07+1 to +2^07-1
short:       -2^15+1 to +2^15-1
int:         -2^15+1 to +2^15-1
long:        -2^31+1 to +2^31-1
long long:   -2^63+1 to +2^63-1
*/


	printf("char test\n");
	char a; //value range : -128 to 127 (1byte - 8bit - 2^8)
	a=127;
	printf("%d\n", a);
	a++;
	printf("%d\n", a);

	printf("unsigned char test\n");
	unsigned char b; //0~255
	b=255;
	printf("%u\n", b);
	b++;
	printf("%u\n", b);


	printf("signed char test\n");
	signed char c; //value range : -128 to 127 (1byte - 8bit - 2^8)
	c=127;
	printf("%d\n", c);
	c++;
	printf("%d\n", c);


	printf("int test\n");
	int d; //value range : - 2147483648 to 2147483647 (4byte - 32bit - 2^32)
	d=2147483647;
	printf("%d\n", d);
	d++;
	printf("%d\n", d);


	printf("unsigned int test\n");
	unsigned int e; //value range : 0 to 4,294,967,295 (2byte. no minus numbers)
	e=4294967295;
	printf("%u\n", e);
	e++;
	printf("%u\n", e);

	printf("short test\n");
	short f; //value range : -32768 to 32767 (2byte - 16bit - 2^16)
	f = 32767;
	printf("%d\n", f);
	f++;
	printf("%d\n", f);
	
	printf("long test\n");
	long g;
	g = 2147483648;
	printf("%li\n", g);

	printf("%li\n", g);
	
	return 0;
}


