#include "JJlog.h"



int main(){
	JJLOG(SYSTEM, "system is test");
	JJLOG(DEBUG, "debug is test");
	JJLOG(ERROR, "error is test");

	SETLOGLEVEL(DEBUG);
	JJLOG(SYSTEM, "system is test");
	JJLOG(DEBUG, "debug is test");
	JJLOG(ERROR, "error is test");
	
	SETLOGLEVEL(ERROR);
	JJLOG(SYSTEM, "system is test");
	JJLOG(DEBUG, "debug is test");
	JJLOG(ERROR, "error is test");
	sleep(3);
	return 0;
}
