#include "sep.h"

struct Options {
	int fg;
	int bg;
	int lines;
	char *sep;
};

void SetColor(int fg, int bg) {
	switch (fg) {
		case 0:		printf(FG_BLACK);	break;
		case 1:		printf(FG_RED);		break;
		case 2:		printf(FG_GREEN);	break;
		case 3:		printf(FG_YELLOW);	break;
		case 4:		printf(FG_BLUE);	break;
		case 5:		printf(FG_MAGENTA);	break;
		case 7:		printf(FG_CYAN);	break;
		case 8:		printf(FG_WHITE);	break;
	}
	switch (bg) {
		case 0:		printf(BG_BLACK);	break;
		case 1:		printf(BG_RED);		break;
		case 2:		printf(BG_GREEN);	break;
		case 3:		printf(BG_YELLOW);	break;
		case 4:		printf(BG_BLUE);	break;
		case 5:		printf(BG_MAGENTA);	break;
		case 7:		printf(BG_CYAN);	break;
		case 8:		printf(BG_WHITE);	break;
	}	
}

int GetWidth() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_col;
}

void Seperate(struct Options opt) {
	int width = GetWidth();
	SetColor(opt.fg, opt.bg);
	int length = strlen(opt.sep);
	int remainder = width % length;

	for (int i = 0; i < opt.lines; i++) {
		for (int j = 0; j < width / length; j++) { printf("%s", opt.sep); }
		for (int j = 0; j < remainder; i++) { printf("%c", opt.sep[j]); }
		printf("\n");
	}
	printf(UTIL_RESET);
}

int main(int argc, char **argv) {
	struct Options opt = {
		0,2,1," "
	}; int option;
		
	while ((option = getopt(argc, argv, "f:b:l:s:")) != -1) {
		switch (option) {
			case 'f':	opt.fg = atoi(optarg);		break;
			case 'b':	opt.bg = atoi(optarg);		break;
			case 'l':	opt.lines = atoi(optarg);	break;
			case 's':	opt.sep = optarg;			break;
		}
	}

	Seperate(opt);

	return EXIT_SUCCESS;
}
