#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <stdbool.h>

#define isCtrlKey(k) ((k) & 0x1f)
#define ESC "\x1b"
#define CLS write(STDOUT_FILENO, "\x1b[2J", 4); // clear the screen
#define CUR_START write(STDOUT_FILENO, "\x1b[1;1H", 3); // position cursor @1:1

/*** TERMINAL ***/
void die(const char *s);
void disableRawMode();
void enableRawMode();
char editorReadKey();

/*** INPUT ***/
void editorProcessKeyPress();

/*** OUTPUT ***/
void editorRefreshScreen();
void writeTilde();
