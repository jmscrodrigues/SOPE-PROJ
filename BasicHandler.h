#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 200

char * BasicString(char *filename);
char ChangeToFile(char *filename, char *msg);
void getExternalCommand(char* filename, char* fileInfo, char* commands[]);
char* HParser(char* filename, char* type);
