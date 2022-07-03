#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <getopt.h>

#include "ANSI.h"

#define VERSION "1.0.0"

struct Options {
	int dice;
	int eyes;
	int rolls;
};

void Version(void) {
	printf("%s\n", VERSION);
}

void Usage(void) {
	printf("%sdice is a tool that let's you roll dice and calculate the average%s\n",UTIL_BOLD,UTIL_RESET);
	printf("Usage: dice <options>\n");
	printf("       -V	Version\n");
	printf("       -h	Help\n");
	printf("       -d	Amount of dice\n");
	printf("       -e	Eyes per die\n");
	printf("       -r	Amound of rolls\n");
}

int Max(int x, int y) {
	return x > y ? x : y;
}

int Roll(int eyes, int dice) {
	int highscore = 0;
	for (int i = 0; i < dice; i++) {
		int score = 1 + rand() % eyes;
		highscore = score > highscore ? score : highscore;
	}
	return highscore;
}

int main(int argc, char **argv) {
	int option;
	struct Options opt = { 1, 6, 65536 };
	while ((option = getopt(argc,argv,"Vhd:e:r:")) != -1) {
		switch (option) {
			case 'V':	Version();	return EXIT_SUCCESS;
			case 'h':	Usage();	return EXIT_SUCCESS;
			case 'd':	opt.dice = atoi(optarg);	break;
			case 'e':	opt.eyes = atoi(optarg);	break;
			case 'r':	opt.rolls = atoi(optarg);	break;
		}
	}

	srand(time(NULL));
	int total = 0;
	for (int i = 0; i < opt.rolls; i++) {	
		printf("%s[ %d / %d ]\n%s",UTIL_CLEARLINE,i+1, opt.rolls,UTIL_UP);
		total += Roll(opt.eyes,opt.dice);
	}

	printf("%s%f\n",UTIL_CLEARLINE,(float)total/(float)opt.rolls);
	return EXIT_SUCCESS;
}
