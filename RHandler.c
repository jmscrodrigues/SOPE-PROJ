#include "RHandler.h"

static char fileToWrite[100];
static char hFlags[50];

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
            RecursiveHandler(str, oFlag, hFlag, vFlag);
            exit(0);
          }
        }
      else {
        printf("File: %s\n", dt->d_name);


        if ((hFlag && vFlag && oFlag) == true) {
          //analise H
          //escrever no o
          //escreve no v
          printf("hvo");
          //VAI SINALIZAR USR2
        }

        else if ((hFlag && vFlag) == true) {
          //analise h
          //escreve no v
          printf("hv");
        }

        else if ((hFlag && oFlag) == true) {
          //analise h
          //escreve no o
          printf("ho");

          //VAI SINALIZAR USR2
        }

        else if ((oFlag && vFlag) == true) {
          char str[50];
          strcpy(str,path);
          strcat(str, "/");
          strcat(str, dt->d_name);

          ChangeToFile(fileToWrite,BasicString(str)); //??, TALVEZ STRCAT(PATH, "/"); STRCAT(PATH,"DT->D_NAME");

          char strwr[50] = "Analized file ";
          strcat(strwr, dt->d_name);
          writeToFileV(strwr);
          char strwr1[50] = "Wrote in file ";
          strcat(strwr1, fileToWrite);
          writeToFileV(strwr1);
        }

        else if (hFlag == true) {
          //analise h
          printf("h");
        }

        else if (oFlag == true) {
          char str[50];
          strcpy(str,path);
          strcat(str, "/");
          strcat(str, dt->d_name);

          ChangeToFile(fileToWrite,BasicString(str));

          //VAI SINALIZAR USR2
        }

        else if (vFlag == true) {
          printf("v\n");
          char str[50];
          strcpy(str,path);
          strcat(str, "/");
          strcat(str, dt->d_name);
          BasicString(str);
          char str1[50] = "Analized file ";
          strcat(str1, dt->d_name);
          writeToFileV(str1);
        }
        else {
          char str[50];
          strcpy(str,path);
          strcat(str, "/");
          strcat(str, dt->d_name);
          printf("%s\n",BasicString(str));
        }

    }
  }

    dt = readdir(dir);



  }

  closedir(dir);
}

void getFileToWrite(char * file) {
  strcpy(fileToWrite, file);
}

void getHFlags(char * flags) {
  strcpy(hFlags, flags);
}
