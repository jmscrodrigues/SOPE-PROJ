#include "RHandler.h"

void RecursiveHandler(char *dirName, bool oFlag, bool hFlag, bool vFlag) {

  DIR *dir;
  struct dirent *dt;

  dir = opendir(dirName);

  if (dir == NULL) {
    perror("-r requires a directory as an argument");
  }

  while ((dt = readdir(dr)) != NULL) {
    if (hFlag && vFlag && oFlag) {
      //DO 1
    }

    else if (hFlag && vFlag) {
      //DO 2
    }

    else if (hFlag && oFlag) {
      //DO 3
    }

    else if (oFlag && vFlag) {
      //DO 4
    }

    else if (hFlag) {
      //DO 5
    }

    else if (oFlag) {
      //DO 6
    }

    else if (vFlag) {
      //DO 7
    }
  }


}
