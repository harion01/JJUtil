#include <stdio.h>

int main(void){
	//& AND operation (both true = true)
	int a = 4;     //0000 0100
	int b = 20;    //0001 0100
	int c = a & b; //0000 0100 = 4
	printf("4 & 20 =%d\n", c);

	//| OR operation (one of both is true = true)
	a = 4;     //0000 0100
	b = 20;    //0001 0100
	c = a | b; //0001 0100 = 20
	printf("4 | 20 =%d\n", c);

	//^ XOR operation (if the value is not match = true)
	a = 4;     //0000 0100
	b = 20;    //0001 0100
	c = a ^ b; //0001 0000 = 16
	printf("4 ^ 20 =%d\n", c);

	//~ Not operation
	a = 4;     //0000 0100
	//~a       //1111 1011 -> 2의 보수로 처리(become negative number)
	unsigned int z = 1;
	printf("~4 = %d , ~unsigned int 10 = %u \n",~a,~z); // z = max value of unsigned int

	// << Left shift operator : x << y = x * (2^y)
	a = 18;
	c = a << 2; // 18*(2^2) = 72
	printf("18 << 2 =%d\n", c);

	// >> Right shift operator : x >> y  = x / (2^y)
	a = 72;
	c = a >> 2; // 72/(2^2) = 18
	printf("72 >> 2 =%d\n", c);
	
	return 0;
}
