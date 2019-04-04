#include "VHandler.h"

#define MAX_SSIZE 100
static clock_t initialTime;
static char filename[MAX_SSIZE];

void writeToFileV (char* event) {
  int fd1;
  int pid;
  int descriptor;
  double elapsedTime;

  fd1 = open(filename, O_APPEND | O_WRONLY | O_CREAT, 0750);

  if (fd1 == -1) {
    perror("Error opening/creating file!");
  }

  pid = getpid();
  elapsedTime = elapsedTimeCalculator();

  descriptor = dup(STDOUT_FILENO);

  dup2(fd1, STDOUT_FILENO);

  close(fd1);

  char elTime[MAX_SSIZE];
  sprintf(elTime, "%f", elapsedTime);
  write(STDOUT_FILENO, elTime, strlen(elTime));
  write(STDOUT_FILENO, " - ", 3);

  char pids[MAX_SSIZE];
  sprintf(pids, "%d", pid);
  write(STDOUT_FILENO, pids, strlen(pids));
  write(STDOUT_FILENO, " - ", 3);
  write(STDOUT_FILENO, event, strlen(event));
  write(STDOUT_FILENO, "\n", 1);

  dup2(descriptor, STDOUT_FILENO);
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
