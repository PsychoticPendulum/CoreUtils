#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define _USE_MATH_DEFINES
#include <math.h>

bool isPrime(int n, int *primes) {
    int index = 0;
    while(primes[index] != 0 && primes[index] < sqrt(n)) {
        if (n % primes[index] == 0) { return false; }
        index++;
    }
    return true;
}

void listPrime(int max) {
    int *primes = malloc(sizeof(int)*max);
    primes[0] = 2;
    int index = 1;
    for (int i = 2; i <= max; i++) {
        if (isPrime(i, primes)) { printf("%d\n", i); primes[index++] = i; }
    }
	free(primes);
}

int main(int argc, char **argv) {
    int max = 1337;
    if (argc > 1) { max = atoi(argv[1]); }
    listPrime(max);
    return 0;
}
