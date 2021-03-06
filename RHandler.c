#include "RHandler.h"

static char fileToWrite[100];
static char hFlags[50];
static int direc = 0;
static int files = 0;
static int initialPid;

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


      //  printf("Dir: %s\n", dt->d_name);

        if (oFlag) {
          kill(initialPid,SIGUSR1);
        }
        int pid = fork();

          if (pid == 0) {
            char *str = calloc(50,1);
            strcpy(str,path);
            strcat(str, "/");
            strcat(str, dt->d_name);


            RecursiveHandler(str, oFlag, hFlag, vFlag);
            exit(0);
          }



        }
      else {


        if ((hFlag && vFlag && oFlag) == true) {
          char *str = calloc(50,1);
          strcpy(str,path);
          strcat(str, "/");
          strcat(str, dt->d_name);

          ChangeToFile(fileToWrite,HParser(str, hFlags));

          char strwr[50] = "Analized file ";
          strcat(strwr, dt->d_name);
          writeToFileV(strwr);

          //files++;
          //VAI SINALIZAR USR2
          kill(initialPid,SIGUSR2);
        }

        else if ((hFlag && vFlag) == true) {
          char *str = calloc(50,1);
          strcpy(str,path);
          strcat(str, "/");
          strcat(str, dt->d_name);

          printf("%s\n", HParser(str, hFlags));
          char strwr[50] = "Analized file ";
          strcat(strwr, dt->d_name);
          writeToFileV(strwr);
        }

        else if ((hFlag && oFlag) == true) {
          char *str = calloc(50,1);
          strcpy(str,path);
          strcat(str, "/");
          strcat(str, dt->d_name);
          ChangeToFile(fileToWrite,HParser(str, hFlags));
          kill(initialPid,SIGUSR2);
          sleep(2);
          //files++;
          //VAI SINALIZAR USR2
        }

        else if ((oFlag && vFlag) == true) {
          char *str = calloc(50,1);
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
          kill(initialPid,SIGUSR2);
          //files++;
          //VAI SINALIZAR USR2
        }

        else if (hFlag == true) {
          char *str = calloc(50,1);
          strcpy(str,path);
          strcat(str, "/");
          strcat(str, dt->d_name);
          printf("%s\n", HParser(str, hFlags));

        }

        else if (oFlag == true) {
          char *str = calloc(50,1);
          strcpy(str,path);
          strcat(str, "/");
          strcat(str, dt->d_name);
          ChangeToFile(fileToWrite,BasicString(str));
          kill(initialPid,SIGUSR2);
          //files++;
          //VAI SINALIZAR USR2
        }

        else if (vFlag == true) {
          //printf("v\n");
          char *str = calloc(50,1);
          strcpy(str,path);
          strcat(str, "/");
          strcat(str, dt->d_name);
          printf("%s\n",BasicString(str));
          char str1[50] = "Analized file ";
          strcat(str1, dt->d_name);
          writeToFileV(str1);
        }
        else {
          char *str = calloc(50,1);
          strcpy(str,path);
          strcat(str, "/");
          strcat(str, dt->d_name);
          printf("%s\n",BasicString(str));
        }
    }
  }
    if (oFlag && (getpid() == initialPid)) {
      sleep(7);
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

void getInitialPid(int pid) {
  initialPid =pid;
}


void signalHandler(int sigNum) {
  if (sigNum == SIGUSR1) {
    direc++;
    if(getpid() == initialPid) {
      printf("New directory: %d/%d directories/files at this time.\n",direc, files);
    }
  }
  else if (sigNum == SIGUSR2) {
    files++;
  }
}
