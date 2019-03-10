#include "BasicHandler.h"

char BasicString(char *filename) {
  struct stat ss;
  int fd1;
  char creationTime[MAX_SIZE];

  fd1 = open(filename, O_RDWR);

  fstat(fd1, &ss);

  strcpy(creationTime, &ss.st_ctime);
  printf("%s\n", creationTime);
  close(fd1);
  return 'a';
}
