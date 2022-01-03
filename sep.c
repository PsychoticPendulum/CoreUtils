#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

// Windows
#include <windows.h>
int get_width() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left;

    return columns;
}

// Linux
// #include <sys/ioctl.h>
/*int getWidth() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_col;
}*/

int main(int argc, char *argv[]) {
    int option;
    char *sym = "-";
    int lines = 1;

    while ((option = getopt(argc, argv, "l:s:")) != -1) {
        switch (option) {
            case 'l':
                lines = atoi(optarg);
                break;
            case 's':
                sym = optarg;
                break;
        }
    }

    int w = get_width();
    int length = strlen(sym);
    int remainder = w % length - 1;
    for (int i = 0; i < lines; i++) {
		for (int j = 0; j < w / strlen(sym); j++) {
			printf(sym);
		}
		for (int k = 0; k < remainder; k++) {
			printf("%c", sym[k]);
		}
		printf("\n");
	}

    return EXIT_SUCCESS;
}
