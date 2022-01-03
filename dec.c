#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void usage() {
    puts("Usage: dec <val> <base>");
}

int get_strlen(char *str) {
    int offset = 0;
    while (str[offset] != 0) {
        offset++;
    }
    return offset;
}

int hex_to_dec(char *val) {
    char hex[] = "0123456789abcdef";
    int length = get_strlen(val);
    int n = 0;
    // -2 for leading '0x', -1 for nulltermination
    int mul = pow(16, length-3);

    for (int i = 2; i < length; i++) {
        for (int j = 0; j < 16; j++) {
            if (val[i] == hex[j]) {
                n += j * mul;
            }
        }
        mul /= 16;
    }
    return n;
}

void dec_to_hex(int dec) {
    unsigned char hex[32];
    char sym[] = "0123456789abcdef";
    bool match = false;
    for (int i = 0; i < 32; i++) {
        hex[i] = 0;
    }
    int index = 0;
    while (dec > 0) {
        hex[index++] = dec % 16;
        dec /= 16;
    }
    printf("0x");
    for (int i = 31; i >= 0; i--) {
        if (hex[i] != 0) {
            match = true;
        }
        if (match) {
            printf("%c", sym[hex[i]]);
        }
    }
    printf("\n");
}

int bin_to_dec(char *val) {
    int length = get_strlen(val);
    int n = 0;
    int mul = pow(2, length-2);
    for (int i = 1; i < length; i++) {
        if (val[i] == '1') {
            n += mul;
        }
        mul /= 2;
    }
    return n;
}

void dec_to_bin(int dec) {
    char bin[32];
    bool match = false;
    for (int i = 0; i < 32; i++) {
        bin[i] = 0;
    }
    int index = 0;
    while (dec > 0) {
        bin[index++] = dec % 2;
        dec /= 2;
    }
    for (int i = 31; i >= 0; i--) {
        if (bin[i] != 0) {
            match = true;
        }
        if (match) {
            printf("%d", bin[i]);
        }
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc <= 2) {
        usage();
        return EXIT_FAILURE;
    }

    char *input = argv[1];
    int n;
    if (input[0] == '0') {
        if (input[1] == 'x') {
            n = hex_to_dec(input);
        } else {
            n = bin_to_dec(input);
        }
    } else {
        n = atoi(input);
    }

    if (!strcmp(argv[2], "d")) {
        printf("%d\n", n);
    } else if (!strcmp(argv[2], "h")) {
        dec_to_hex(n);
    } else if (!strcmp(argv[2], "b")) {
        dec_to_bin(n);
    } else {
        printf("Unknown base: %s\n", argv[2]);
    }

    return EXIT_SUCCESS;
}
