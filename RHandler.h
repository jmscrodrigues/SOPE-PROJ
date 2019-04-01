#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "BasicHandler.h"
#include "VHandler.h"

void getFileToWrite(char * file);
void getHFlags(char * flags);
void RecursiveHandler(char * path, bool oFlag, bool hFlag, bool vFlag);
