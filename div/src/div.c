#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <getopt.h>

struct Options {
	bool list_all;
};

void GetDivisors(int n, struct Options opt) {
    bool prime = true;
    printf("%d\n'->  ", n);
    n = abs(n);
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            printf("%d  ", i);
            prime = false;
        }
    }
    if (prime) {
        printf("Prime");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
	struct Options opt = { false };
	int option;
	for ((option = getopt(argc, argv, "l")) != -1) {
		switch (option) {
			case 'l':	opt.list_all = true;	break;
		}
	}
	
	int n = 0;
	for (; optind < argc; optind++) { n = atoi(optarg); }
   
	GetDivisors(n, opt);

    return EXIT_SUCCESS;
}
