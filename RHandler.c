#include "RHandler.h"

static char filetoWrite[100];

void RecursiveHandler(char * path, bool oFlag, bool hFlag, bool vFlag) {


  struct dirent *dt;
  DIR *dir = opendir(path);

  if(dir == NULL) {
    printf("ERROR, not a directory\n");
    return;
  }

  dt = readdir(dir);

  while (dt!= NULL) {

    if ( (strcmp(dt->d_name, ".") != 0) && (strcmp(dt->d_name, "..") != 0) ) {
      if (dt->d_type == DT_DIR) {
        printf("Dir: %s\n", dt->d_name);
        int pid = fork();
          if (pid == 0) {
            char str[50];
            strcpy(str,path);
            strcat(str, "/");
            strcat(str, dt->d_name);
            RecursiveHandler(str, false, false, false);
            exit(0);
          }
        }
      else {
        printf("File: %s\n", dt->d_name);
        if (hFlag && vFlag && oFlag) {
          //analise H
          //escrever no o
          //escreve no v

          //VAI SINALIZAR USR2
        }

        else if (hFlag && vFlag) {
          //analise h
          //escreve no v
        }

        else if (hFlag && oFlag) {
          //analise h
          //escreve no o

          //VAI SINALIZAR USR2
        }

        else if (oFlag && vFlag) {
          BasicString(dt->d_name); //??, TALVEZ STRCAT(PATH, "/"); STRCAT(PATH,"DT->D_NAME");
          //escreve no v e o
        }

        else if (hFlag) {
          //analise h
        }

        else if (oFlag) {
          //analise normal
          //escreve no o

          //VAI SINALIZAR USR2
        }

        else if (vFlag) {
          //analise normal
          //escreve no v
        }

    }
  }

    dt = readdir(dir);



  }

  closedir(dir);
}

void getFileToWrite(char * file) {
  strcpy(filetoWrite, file);
}
