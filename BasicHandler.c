#include "BasicHandler.h"

char BasicString(char *filename) {
  struct stat ss;
  int fd1;

  off_t size;
  char modifyDate[20];
  char creationDate[20];
  mode_t permission;
  char permissionOwner[3];
  fd1 = open(filename, O_RDWR);

  fstat(fd1, &ss);

  size = ss.st_size; //FILE_SIZE (nao sei porque mas se tiver só 1 caracter aparece que tem 2 e assi por diante!)
  strftime(modifyDate, 20, "%d-%m-%yT%H:%M:%S", localtime(&(ss.st_mtime))); //DATA DE ULTIMA MODIFICAÇAO
  strftime(creationDate, 20, "%d-%m-%yT%H:%M:%S", localtime(&(ss.st_ctime))); //DATA DE CRIACAO

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


char ChangeToFile(char *filename, char *filename1)    // -o
{

  int copy;
  int file = open(filename, O_APPEND | O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

  copy = dup(STDOUT_FILENO);

  dup2(file, STDOUT_FILENO);

  close(file);

  //char *msg = "Ola";
  write(STDOUT_FILENO, msg, strlen(msg));

  dup2(copy, STDOUT_FILENO);

  printf("Data saved on file %s\n", filename );
  printf("Execution records saved on file ... \n");

  return 0;
}
