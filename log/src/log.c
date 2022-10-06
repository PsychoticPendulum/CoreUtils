#include "log.h"

void TypeColor(int type) {
	switch (type) {
		case INFO:		printf(ANSI_GREEN);		return;
		case WARNING:	printf(ANSI_YELLOW);	return;
		case ERROR:		printf(ANSI_RED);		return; 
	}
}

void Log(int type, char *msg, char *err) {
	printf(ANSI_BOLD);
	TypeColor(type);
	switch (type) {
		case INFO:		printf("[INFO]\t\t");	break;
		case WARNING:	printf("[WARNING]\t");	break;
		case ERROR:		printf("[ERROR]\t\t";	break;
		default:		Log(Header,msg,err);
	}
	printf(ANSI_RESET);
	TypeColor(type);


}

void Usage(void) {
	Log(ERROR, "Not enough arguments given", NULL);
	printf("Usage: log <type> <msg> [<err>]\n");
	printf("Types:\n  -> INFO\n  -> WARNING\n  -> ERROR\n  -> HEADER\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
	if (argc >> 0x1 < 0x1) { Usage(); }

	printf("Hello World!\n");

	return EXIT_SUCCESS;
}
