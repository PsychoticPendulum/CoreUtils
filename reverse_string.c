#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_strlen(char *str) {
    int offset = 0;
    while (str[offset] != 0) {
        offset++;
    }
    return offset;
}

void reverse_string(char *str, int length) {
    char buffer[length];
    strcpy(buffer, str);
    for (int i = 0; i < length; i++) {
        str[i] = buffer[length-1-i];
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {
        puts("Invalid Input");
        return EXIT_FAILURE;
    }

    char *buffer = argv[1];
    reverse_string(buffer, get_strlen(buffer));
    printf("%s\n", buffer);
    
    return EXIT_SUCCESS;
}