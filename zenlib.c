#include "zenedit.h"

struct termios orig_termios;

/*** FUNCTION DEFINITIONS ***/
void die(const char *s) {
  perror(s);
  printf("%d\r\n", errno);
  exit(1);
}
void disableRawMode() {
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1) {
    die("tcsettar at disableRawMode()");
  }
}

void enableRawMode() {
  if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) {
    die("tcgetattr at enableRawMode");
  }
  atexit(disableRawMode); // disable at exit

  struct termios raw = orig_termios;
  // ICRNL disables carriage return & new line calls every time '\n' is called
  raw.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
  raw.c_oflag &= ~(OPOST);
  raw.c_cflag &= (CS8);
  raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN); // disable canon input
  raw.c_cc[VMIN] = 0; // min chars needed before returning read()
  raw.c_cc[VTIME] = 1; // 100 ms for every read() call

  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
    die("tcsetattr at enableRawMode");
  }
}

