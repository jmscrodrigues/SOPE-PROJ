#include "VHandler.h"

void writeToFileV (char *filename) {
  int fd1;
  int pid;


  if (strstr(filename, ".txt") != ".txt") {
    strcat(filename, ".txt");
  }

  fd1 = open(filename, O_WRONLY | O_CREAT, 0750);

  if (fd1 == -1) {
    perror("Error opening/creating file!");
  }

  pid = getpid();

  printf("%d\n", pid);
  


}
