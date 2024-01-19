/*** INCLUDES ***/
#include "zenedit.h"

/*** DEFINES ***/
#define CTRL_KEY(k) ((k) & 0x1F)

/*** MAIN ENTRY ***/
int main() {
  enableRawMode(); // makes sure that what we type is not printed to term

  while (1) {
    char c = '\0';
    if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) {
      die("read at entry");
    }

    if (iscntrl(c)) {
      printf("%d\r\n", c);
    } else {
      printf("%d - (%c)\r\n", c, c);
    }

    if (c == CTRL_KEY('q')) {
      break;
    } 
  }
  return 0;
}
