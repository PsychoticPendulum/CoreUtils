#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <getopt.h>

#define BASE    0x0
#define KILO    0x1
#define MEGA    0x2
#define GIGA    0x3

void Usage(bool help) {
    printf("Usage: con -i <input> -o <output>\n");
    if (help) {
        printf("  Known Types:\n");
        printf("    B   b\n");
        printf("    KB Kb KiB Kib\n");
        printf("    MB Mb MiB Mib\n");
        printf("    GB Gb GiB Gib\n");
    }
}

// Returns a character in lowercase
// This approach is completely branchless using the C99 standard
char Lower(const char c) {
	return c + 0x20 * ((c > 0x60) + (c < 0x7b) – 0x1);
}

// Returns the lengths (in chars) of a char pointer
int Length(char *str) {
    int index = 0;
    while (str[index]) { index++; }
    return index;
}

// Returns true if a char pointer contains a char
bool Contains(char *str, const char c) {
	int index = 0;
	while(str[index]) { if (str[index++] == c) { return true; } }
	return false;
}

// Extracts an integer from a char pointer
// Stops at first character that is no integer
double ExtractNumber(char *str) {
    int index = 0;
    char *num = malloc(sizeof(char)*0xf);
    for (int i = 0; i < Length(str); i++) {
        if (str[i] >= 0x30 && str[i] <= 0x39) {
            num[index++] = str[i];
        }
    }
    index = atoi(num);
    free(num);
    return (double)index;
}

int Type(char *str) {
    char c[] = "_KMG";
    for (int i = GIGA; i > BASE; i--) {
        if (Contains(str, c[i])) { return i; }
    }
    return BASE;
}

double Pow(double base, double exponent) {
	double result = base;
	for (int i = 1; i < (int)exponent; i++) { result *= base; }
	return result;
}

double ToByte(bool binary, int t, double n) {
	double base = binary ? 2.0 : 10.0;
	double exponent = binary ? ((double)t*10.0) : ((double)t*3.0);
	n*=Pow(base,exponent);
    return n;
}

double ToResult(bool binary, int t, double n) {
    int base = binary ? 0x2 : 0xa;
	int exponent = binary ? (t*0xa) : (t*0x3);
	n/=Pow(base,exponent);
    return n;
}

int main(int argc, char **argv) {
    // Handle command line arguments
    int option;
    char *in; char *out;
    while ((option = getopt(argc, argv, "i:o:h")) != -1) {
        switch (option) {
            case 'i': in = optarg;  break;
            case 'o': out = optarg; break;
            case 'h': Usage(true);  return EXIT_SUCCESS;
        }
    }

    // Exit if insufficient amount of arguments was given
    if (argc < 0x5) { Usage(false); return EXIT_FAILURE; }
    
    double n = ExtractNumber(in);
    if (Contains(in, 'B')) { n/=8; }
	n = ToByte(Contains(in, 'i'), Type(in), n);
    n = ToResult(Contains(out, 'i'), Type(out), n);
    if (Contains(out, 'B')) { n*=8; }
    printf("%f%s\n", n, out);

    return EXIT_SUCCESS;
}
