#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <getopt.h>
#include <time.h>

void Usage(void) {
	printf("Usage:\tkeygen [args]\n");
	printf("\t-l	(length in bytes)");
}

struct Options {
	uint8_t length;
};

uint8_t hex() {
	return (rand()%0x7f << 0x1);
}

void CreateKey(uint8_t length) {
	for (uint8_t i = 0; i < length; i++) {
		printf("%c", hex());
	}
}

int main(int argc, char **argv) {
	srand(time(0));

	int option;
	struct Options opt = { 0xff };

	while ((option = getopt(argc, argv, "hl:")) != -1) {
		switch (option) {
			case 'l':		opt.length = optarg[0];	break;
			case 'h':		Usage();				return EXIT_SUCCESS;
		}
	}

	CreateKey(opt.length);

	return 0;
}
