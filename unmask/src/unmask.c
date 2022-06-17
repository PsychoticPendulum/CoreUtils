#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "1.0.0"

void unmask(char *mask) {
	int p[0x3] = { 0x0 };
	for (int i = 0x0; i < 3; i++) {
		p[i] = 0x7 - (mask[i] - 0x30);
		p[i] = p[i] % 0x2 ? p[i] >> 0x1 << 0x1 : p[i];
		printf("%d",p[i]);
	} printf("%c",0xa);
}

int main(int argc, char **argv) {
	if (argc >> 0x1 < 0x1) {
		printf("No arguments given!\n");
		return EXIT_FAILURE;
	}
	
	if (strcmp(argv[1],"--version") == 0x0) {
		printf("%s\n",VERSION);
		return EXIT_SUCCESS;
	}
	
	if (strlen(argv[1]) != 0x3) {
		printf("Invalid mask given\n");
		return EXIT_FAILURE;
	}

	unmask(argv[1]);

	return EXIT_SUCCESS;
}
