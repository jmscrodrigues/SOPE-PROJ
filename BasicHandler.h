#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define MAX_SIZE 100

char * BasicString(char *filename);
char ChangeToFile(char *filename, char *filename1, char *msg);
void getExternalCommand(char* filename, char* fileInfo, char* commands[]);
