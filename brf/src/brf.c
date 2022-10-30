#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <getopt.h>

void Iterate(char *set, int depth) {
	
}

int main(int argc, char **argv) {
	if (argc < 2) { return EXIT_FAILURE; }
	Iterate(argv[1],2);
	return EXIT_SUCCESS;
}
