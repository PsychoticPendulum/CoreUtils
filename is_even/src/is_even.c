#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Thanks to infiniteStorms
bool is_even_bitshift_2(int n) {
	return ((abs(n) >> 0x1) << 0x1) == n;
}

// Thanks to ngiqzang2708
bool is_even_and(int n) {
    return (n & 0x1) == 0x0;
}

// Thanks to lnnf107
bool is_even_mutual_recursion(int n);
bool is_odd_mutual_recursion(int n);
bool is_even_mutual_recursion(int n) {
    if (n == 0)
        return true;
    return is_odd_mutual_recursion(n-1);
}
bool is_odd_mutual_recursion(int n) {
    if (n == 0)
        return false;
    return is_even_mutual_recursion(n-1);
}

bool is_even_binary(int n) {
    int bin[32];
    int index = 0;
    while (abs(n) > 0) {
        bin[index++] = n % 2;
        n /= 2;
    }
    return !bin[0];
}

bool is_even_bitshift(int n) {
    return (abs(n << 0x1f) == 0x0);
}

bool is_even_last_digit(int n) {
    int len = log10(n);
    char str_n[len];
    sprintf(str_n,"%d", n);
    return (str_n[len] == '0' ||
            str_n[len] == '2' ||
            str_n[len] == '4' ||
            str_n[len] == '6' ||
            str_n[len] == '8');
}

bool is_even_subtraction(int n) {
    n = abs(n);
    while (n > 1) {
        n -= 2;
    }
    return (n != 1);
}

bool is_even_logical(int n) {
    return !(n % 2);
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("No input found ...\n");
        return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);
    if (!n) {
        printf("Invalid input\n");
        return EXIT_FAILURE;
    }

    printf("%d is %seven\n", n, is_even_mutual_recursion(n) ? "" : "not ");

    return EXIT_SUCCESS;
}