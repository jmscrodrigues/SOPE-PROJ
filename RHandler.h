#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>


void RecursiveHandler(DIR *dir, bool oFlag, bool hFlag, bool vFlag);
