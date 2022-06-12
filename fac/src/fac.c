#include <stdio.h>
#include <stdlib.h>

long long fac(int n) {
	long long result = n;
	for (int i = n - 1; i > 0; i--) {
		result *= i;
	}
	return result;
}

int main(int argc, char **argv) {
	if (argc >> 0x1 < 0x1) {
		printf("Invalid input\n");
		return EXIT_FAILURE;
	}
	long long n = fac(atoi(argv[1]));
	printf("%lld\n", n > 0 ? n : 0);
	return EXIT_SUCCESS;
}
