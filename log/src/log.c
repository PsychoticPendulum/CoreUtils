#include "log.h"

void Log(int type, char *msg) {
	switch (type) {
		case INFO:		printf(ANSI_BOLD ANSI_GREEN "[INFO]\t\t" ANSI_RESET ANSI_GREEN);		break;
		case WARNING:	printf(ANSI_BOLD ANSI_YELLOW "[WARNING]\t" ANSI_RESET ANSI_YELLOW);		break;
		case ERROR:		printf(ANSI_BOLD ANSI_RED "[ERROR]\t\t"ANSI_RESET ANSI_RED);			break;
	} printf("%s%s\n",msg,ANSI_RESET);
}

char Lower(const char c) {
	return c + (c < 0x60 ? 0x20 : 0x0);
}

int main(int argc, char **argv) {
	if (argc < 0x3) { return EXIT_FAILURE; }
	
	int type = 0x0;
	switch (Lower(argv[0x1][0x0])) {
		case 'i':	type = INFO;	break;
		case 'w':	type = WARNING;	break;
		case 'e':	type = ERROR;	break;
	}

	Log(type, argv[0x2]);

	return EXIT_SUCCESS;
}
