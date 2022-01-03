#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split(char *str, char sep) {
    int offset = -1;
    while(str[offset++] != 0) {
        if (str[offset] == sep) {
            printf("\n");
            continue;
        }
        printf("%c", str[offset]);
    }
}

int main(int argc, char **argv) {
    char buffer[] = "My name is Steve";
    char seperator = ' ';
    split(buffer, seperator);
    return EXIT_SUCCESS;
}