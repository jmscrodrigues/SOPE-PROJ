#include "VHandler.h"

static clock_t initialTime;

void writeToFileV (char *filename, char* event) {
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
}

void clockInitialTime () {
  initialTime = clock();
}

double elapsedTimeCalculator() {
  double elapsedTime;
  clock_t calcTime = clock();
  calcTime -= initialTime;
  elapsedTime = ((double) calcTime/CLOCKS_PER_SEC);
  return elapsedTime;
}
