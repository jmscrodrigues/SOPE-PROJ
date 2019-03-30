#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>


void RecursiveHandler(char * file, DIR *dir, bool oFlag, bool hFlag, bool vFlag);
