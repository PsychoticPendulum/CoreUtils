#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <getopt.h>

#define VERSION "1.0.0"

void Version(void) {
	printf("%s\n",VERSION);
}

void Usage(void) {
	printf("Usage: ust <time>\n");
}

int main(int argc, char **argv) {
	if (argc == 2) {
		if (strcmp(argv[1],"--version") == 0) {
			Version();
			return EXIT_SUCCESS;
		}
	} else { Usage(); return EXIT_FAILURE; }
	
	signed int ust = atoi(argv[1]);

	return EXIT_SUCCESS;	
}
