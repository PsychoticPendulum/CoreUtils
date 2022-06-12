#pragma once

#include <stdio.h>
#include <stdlib.h>

#define INFO		0x0
#define WARNING		0x1
#define ERROR		0x2

#define ANSI_RED	"\x1b[31m"
#define ANSI_YELLOW	"\x1b[33m"
#define ANSI_GREEN	"\x1b[32m"
#define ANSI_BOLD	"\x1b[1m"
#define ANSI_RESET	"\x1b[0m"

void Log(int type, char *msg, char *err);
