#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>

void die(const char *s);
void disableRawMode();
void enableRawMode();
