#include "BasicHandler.h"

char BasicString(char *filename) {
  struct stat ss;
  int fd1;

  off_t size;
  char date[20];
  mode_t permission;
  char permissionOwner[3];
  fd1 = open(filename, O_RDWR);

  fstat(fd1, &ss);

  size = ss.st_size; //FILE_SIZE (nao sei porque mas se tiver só 1 caracter aparece que tem 2 e assi por diante!)
  strftime(date, 20, "%d-%m-%yT%H:%M:%S", localtime(&(ss.st_mtime)));

  permission = ss.st_mode;
  if ((permission & S_IRUSR) == 0) {
  }
  else {
    char read[] = "r";
    strcat(permissionOwner, read);
  }

  if ((permission & S_IWUSR) == 0) {
  }
    else {
      char write[] = "w";
      strcat(permissionOwner, write);
    }

  if ((permission & S_IXUSR) == 0) {
  }
    else {
      char execute[] = "x";
      strcat(permissionOwner, execute);
    }



  close(fd1);
}
