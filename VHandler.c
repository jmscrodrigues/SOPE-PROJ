#include "VHandler.h"

#define MAX_SSIZE 100
static clock_t initialTime;
static char filename[MAX_SSIZE];

void writeToFileV (char* event0) {
  int fd1;
  int pid;
  double elapsedTime;

  fd1 = open(filename, O_WRONLY | O_CREAT, 0750);

  if (fd1 == -1) {
    perror("Error opening/creating file!");
  }

  pid = getpid();
  elapsedTime = elapsedTimeCalculator();
  
}

void clockInitialTime () {
  initialTime = clock();
}

void getLogFilename(char *name) {
  strcpy(filename, name);
}

double elapsedTimeCalculator() {
  double elapsedTime;
  clock_t calcTime = clock();
  calcTime -= initialTime;
  elapsedTime = ((double) calcTime/CLOCKS_PER_SEC);
  return elapsedTime;
}
