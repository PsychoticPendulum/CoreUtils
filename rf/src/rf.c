#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>

struct Options {
	bool		help;
	bool		ln;
	bool		rp;
	char		sym;
}; 

void help() {
	printf("Usage: rf <args> <file>\n");
	printf("\tl  ->  show line numbers\n");
	printf("\th  ->  show help menu\n");
	printf("\tr  ->  replace char with symbol\n");
}

void readfile(char *filename, struct Options opt) {
	char c;
	int lc = 0;
	FILE *fptr;
	fptr = fopen(filename, "r");

	if (fptr == NULL) {
		printf("Error reading file: %s\n", filename);
		return;
	}

	printf("File: %s\n", filename);
	if (opt.ln) 
		printf("0\t");
	while ((c = fgetc(fptr)) != EOF) {
		if (opt.ln && c == 0xa) {
			printf("\n%d\t", ++lc);
			continue;
		}
		printf("%c", opt.rp ? opt.sym : c);
	}
}

int main(int argc, char **argv) {
	int option;
	char *file;
	struct Options opt = {
		false,	false,
		false,	'a'
	};

	while ((option = getopt(argc, argv, "hlr:")) != -1) {
		switch (option) {
			case'h':
				opt.help = true;
				break;
			case 'l':
				opt.ln = true;
				break;
			case 'r':
				opt.rp = true;
				opt.sym = optarg[0];
				break;
		}
	}

	if (opt.help) {
		help();
		return EXIT_SUCCESS;
	}

	if (!isatty(STDIN_FILENO)) {
		char input;
		while (read(STDIN_FILENO, &input, 1) != 0) {
			printf("%c", input);
		}
	}

	for (; optind < argc; optind++) {
		file = argv[optind];
		readfile(file, opt);
	}

	return EXIT_SUCCESS;
}
