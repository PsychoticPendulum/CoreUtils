#include <stdio.h>
#include <stdlib.h>

#include <getopt.h>

struct Options {
	int x;
};

void Usage(void) {
	printf("Usage:	ss <month>/<day>/<year>\n");	
}

void ParseDate(char *date, int *day, int *month, int *year) {
	int pos = 0;
	for (int i = 0; i < 2; i++) {
		if (date[i] = 0) { break; }

	}
}

int main(int argc, char **argv) {
	if (argc < 0x2) { return EXIT_FAILURE; }
	
	int option;
	struct Options opt = { 0 };
	while ((option = getopt(argc, argv, "h")) != -1) {
		switch (option) {
			case 'h':	Usage();	break;	
		}
	}

	int m,d,y;
	ParseDate(argc[1],&m,&d,&y);

	return EXIT_SUCCESS;
}
