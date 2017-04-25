#include "OpenAddressing.h"

int main(void){

	HashTable* HT = OAHT_CreateHashTable(11);

	OAHT_Set( &HT, "MSFT" , "MS coperation");
	OAHT_Set( &HT, "JAVA" , "SUN");
	OAHT_Set( &HT, "REDH" , "Red Hat Linux");
	OAHT_Set( &HT, "APAC" , "Apach Org");
	OAHT_Set( &HT, "ZYMZZ" , "Unisys"); //collision with APAC
	OAHT_Set( &HT, "IBM" , "IBM");
	OAHT_Set( &HT, "ORCL" , "Oracle");
	OAHT_Set( &HT, "CSCO" , "Cisco");
	OAHT_Set( &HT, "GOOG" , "Google");
	OAHT_Set( &HT, "YHOO" , "Yahoo");
	OAHT_Set( &HT, "NOVL" , "Novell");

	printf("\n");
	printf("Key[%s], Value[%s]\n", "MSFT", OAHT_Get(HT, "MSFT"));
	printf("Key[%s], Value[%s]\n", "JAVA", OAHT_Get(HT, "JAVA"));
	printf("Key[%s], Value[%s]\n", "REDH", OAHT_Get(HT, "REDH"));
	printf("Key[%s], Value[%s]\n", "APAC", OAHT_Get(HT, "APAC"));
	printf("Key[%s], Value[%s]\n", "ZYMZZ", OAHT_Get(HT, "ZYZMM"));
	printf("Key[%s], Value[%s]\n", "IBM", OAHT_Get(HT, "IBM"));
	printf("Key[%s], Value[%s]\n", "ORCL", OAHT_Get(HT, "ORCL"));
	printf("Key[%s], Value[%s]\n", "CSCO", OAHT_Get(HT, "CSCO"));
	printf("Key[%s], Value[%s]\n", "GOOG", OAHT_Get(HT, "GOOG"));
	printf("Key[%s], Value[%s]\n", "YHOO", OAHT_Get(HT, "YHOO"));
	printf("Key[%s], Value[%s]\n", "NOVL", OAHT_Get(HT, "NOVL"));





	return 0;
}
