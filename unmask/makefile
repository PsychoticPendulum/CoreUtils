NAME=unmask
CC=gcc
CFLAGS=-Wall -std=c99
LIBS=

all: src/*.c
	$(CC) src/*.c -o $(NAME) $(CFLAGS) $(LIBS)

debug: src/*.c
	$(CC) src/*.c -o $(NAME) $(CFLAGS) -g $(LIBS)
