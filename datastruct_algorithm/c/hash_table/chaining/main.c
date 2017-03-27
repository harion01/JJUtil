#include "Chaining.h"

int main(void){
	HashTable* HT = CHT_CreateHashTable(2);

	CHT_Set(HT, 418, "test");
	CHT_Set(HT, 418, "test1111");
	CHT_Set(HT, 9, "test2");
	CHT_Set(HT, 27, "test3");
	CHT_Set(HT, 1031, "test4");
	
	printf("Key:%d, Value:%s\n", 418, CHT_Get(HT, 418));
	printf("Key:%d, Value:%s\n", 9, CHT_Get(HT, 9));
	printf("Key:%d, Value:%s\n", 27, CHT_Get(HT, 27));
	printf("Key:%d, Value:%s\n", 1031, CHT_Get(HT, 1031));

	return 0;
}
