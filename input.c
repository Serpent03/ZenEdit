#include "common_headers.h"

void editorProcessKeyPress() {
  char c = editorReadKey();
  switch (c) {
    case isCtrlKey('q'):
      editorRefreshScreen();
      exit(0);
      break;
  } 
}
