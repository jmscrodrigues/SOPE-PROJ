#include "BasicHandler.h"

char BasicString(char *filename) {
  struct stat ss;
  int fd1;
  off_t size;

  fd1 = open(filename, O_RDWR);

  fstat(fd1, &ss);
  size = ss.st_size; //FILE_SIZE (nao sei porque mas se tiver só 1 caracter aparece que tem 2 e assi por diante!)

  close(fd1);
}
