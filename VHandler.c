#include "VHandler.h"

void writeToFileV (char *filename) {
  int fd1;

  fd1 = open(filename, O_WRONLY | O_CREAT, 0750);

  if (fd1 == -1) {
    perror("Error opening/creating file!");
  }

  

}
