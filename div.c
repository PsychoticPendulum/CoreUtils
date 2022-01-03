#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int abs(int n) {
    if (n < 0) {
        n *= -1;
    }
    return n;
}

void get_div(int n) {
    bool prime = true;
    printf("%d  ->  ", n);
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
    int n = 0;
    for (int i = 1; i < argc; i++) {
        n = atoi(argv[i]);
        if (n == 0) {
            printf("%s NAN\n", argv[i]);
        } else {
            get_div(n);
        }
    }
    
    return EXIT_SUCCESS;
}