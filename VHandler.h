#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 200

void clockInitialTime();
void getLogFilename(char *name);
void writeToFileV (char *event);
double elapsedTimeCalculator();
