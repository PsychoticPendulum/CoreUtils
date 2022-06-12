NAME=is_even
CC=gcc
CFLAGS=-Wall -std=c99
LIBS=-lm

all: src/*.c
	$(CC) src/*.c -o $(NAME) $(CFLAGS) $(LIBS)

debug: src/*c
	$(CC) src/*.c -o $(NAME) $(CFLAGS) -g $(LIBS)
