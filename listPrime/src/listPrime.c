#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <getopt.h>

#define BINARY		0x0
#define DECIMAL		0x1
#define HEXADECIMAL	0x2

struct Options {
	int max;
	int base;
};

void Usage(void) {
	printf("Usage: lp <args>\n");
	printf("       -h	Show help menu\n");
	printf("       -m	Max value\n");
}

bool IsPrime(int n, int *primes) {
	int index = 0;
	while (primes[index] != 0x0 && primes[index] < sqrt(n)) {
		if (n % primes[index] == 0x0) { return false; }
		index++;
	} return true;
}

int GetBase(char *c) {
	if (*c == 'b') { return BINARY; }
	if (*c == 'd') { return DECIMAL; }
	return HEXADECIMAL;
}

void ListPrime(struct Options *opt) {
	int *primes = malloc(sizeof(int)*opt->max);	
	primes[0] = 0x2;
	int index = 0x1;
	for (int i = 0x2; i <= opt->max; i++) {
		if (IsPrime(i, primes)) { 
			switch (opt->base) {
				case BINARY:		printf("0b%b\n",i);	break;
				case DECIMAL:		printf("%d\n",i);	break;
				case HEXADECIMAL:	printf("0x%x\n",i);	break;
			} primes[index++] = i;
		}
	} free(primes);
}

int main(int argc, char **argv) {
	int option;
	struct Options opt = { 0xffff, 0x1 };
	while ((option = getopt(argc, argv, "m:b:h")) != -1) {
		switch (option) {
			case 'm':		opt.max = atoi(optarg);		break;
			case 'b':		opt.base = GetBase(optarg);	break;
			case 'h':		Usage();					return EXIT_SUCCESS;
		}
	}
	ListPrime(&opt);
	return EXIT_SUCCESS;	
}
