#include "common_headers.h"

void editorRefreshScreen() {
  CLS;
  CUR_START;
}

void writeTilde() {
  for (int y = 0; y < 25; y++) {
    write(STDOUT_FILENO, "~\r\n", 1+2); // +2 bytes to include \r and \n
  }
}
