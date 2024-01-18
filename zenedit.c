#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>

struct termios orig_termios;
void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode); // disable at exit

  struct termios raw = orig_termios;
  raw.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
  raw.c_oflag &= ~(OPOST);
  raw.c_cflag &= (CS8);
  raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN); // disable canon input
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
  enableRawMode(); // makes sure that what we type is not printed to term

  char c;
  while (read(STDIN_FILENO, &c, 1) == 1) {
    if (c == 'q') {
      break;
    } else if (iscntrl(c)) {
      printf("%d\r\n", c);
    } else {
      printf("%d - (%c)\r\n", c, c);
    }
  }
  return 0;
}
