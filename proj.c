#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "BasicHandler.h"
#include "VHandler.h"
#include "RHandler.h"

void sigint_handler(int signo) {
  printf("SIGINT received ... \n");
  exit(2);
}

int main(int argc, char **argv, char **envp) {

  signal(SIGINT, sigint_handler);
  signal(SIGUSR1, signalHandler);
  signal(SIGUSR2, signalHandler);
  getInitialPid(getpid());
  clockInitialTime();

  if ((argc < 2) || (argc > 8)) {
    printf("Too many/little arguments!\n");
    return -1;
  }

  else if (argc % 2 != 0) {

    if (argc == 3) {
      //FAZER PARA O -R OU PARA O -V

      if (strcmp(argv[1], "-r") == 0) {
        char file[strlen(argv[2])];
        strcpy(file,argv[2]);
        char *path;
        char actualpath[200];
        path = realpath(file,actualpath);
        if (path) {
          RecursiveHandler(path,false, false, false);
        }
    }

      else if (strcmp(argv[1], "-v") == 0) {
        char file[strlen(argv[2])];
        strcpy(file,argv[2]);
        char logfile[100];
        char event[100];
        for (int i = 0; envp[i] != NULL; i++) {
          if (strncmp(envp[i], "LOGFILENAME", 11) == 0) {
            strcpy(logfile, envp[i]);
            strtok(logfile, "=");
            strcpy(logfile,strtok(NULL, "="));
            getLogFilename(logfile);
            break;
          }
        }
        printf("%s\n",BasicString(file));
        strcpy(event, "Analized file ");
        strcat(event, file);
        writeToFileV(event);
      }
      else  {
        printf("Wrong parameters");
        return -1;
      }

    }

    else if (argc == 5) {
      //FAZER PARA O -R OU -V

      if (strcmp(argv[1], "-r") == 0) {

        if (strcmp(argv[2], "-h") == 0) {
          getHFlags(argv[3]);
          char file[strlen(argv[4])];
          strcpy(file,argv[4]);

          char *path;
          char actualpath[200];
          path = realpath(file,actualpath);
          if (path) {
            RecursiveHandler(path,false, true, false);
          }

          // PRINTF BASICHANDLER
        }


        else if (strcmp(argv[2], "-o") == 0) {
          getFileToWrite(argv[3]);
          char file[strlen(argv[4])];
          strcpy(file,argv[4]);
          char *path;
          char actualpath[200];
          path = realpath(file,actualpath);
          if (path) {
            RecursiveHandler(path,true, false, false);
          }

        }
        else  {
          printf("Wrong parameters");
          return -1;
        }
      }

      else if (strcmp(argv[3], "-v") == 0) {

        if (strcmp(argv[1], "-h") == 0) {
          char str[strlen(argv[2])];
          strcpy(str, argv[2]);
          char file[strlen(argv[4])];
          strcpy(file,argv[4]);
          char logfile[100];
          for (int i = 0; envp[i] != NULL; i++) {
            if (strncmp(envp[i], "LOGFILENAME", 11) == 0) {
              strcpy(logfile, envp[i]);
              strtok(logfile, "=");
              strcpy(logfile,strtok(NULL, "="));
              getLogFilename(logfile);
              break;
            }
          }
          printf("%s\n",HParser(file, str));
          char strwr[50] = "Analized file ";
          strcat(strwr, file);
          writeToFileV(strwr);

          //FICHEIRO DO -V E -H (vai envolver o envp -V)
        }

        else if (strcmp(argv[1], "-o") == 0) {
          char writeFilename[strlen(argv[2])];
          strcpy(writeFilename,argv[2]);
          char file[strlen(argv[4])];
          strcpy(file,argv[4]);
          char logfile[100];
          for (int i = 0; envp[i] != NULL; i++) {
            if (strncmp(envp[i], "LOGFILENAME", 11) == 0) {
              strcpy(logfile, envp[i]);
              strtok(logfile, "=");
              strcpy(logfile,strtok(NULL, "="));
              getLogFilename(logfile);
              break;
            }
          }

          ChangeToFile(writeFilename, BasicString(file));
          char strwr[50] = "Analized file ";
          strcat(strwr, file);
          writeToFileV(strwr);


          //FICHEIRO DO -V E -O (vai envolver o envp -V)
        }

        else  {
          printf("Wrong parameters");
          return -1;
        }
      }
    }

    else {

      if (strcmp(argv[1], "-r") == 0) {
        getHFlags(argv[3]);
        getFileToWrite(argv[5]);
        char file[strlen(argv[6])];
        strcpy(file,argv[6]);

        char *path;
        char actualpath[200];
        path = realpath(file,actualpath);
        if (path) {
          RecursiveHandler(path,true, true, false);
        }

    }

      else if (strcmp(argv[5], "-v") == 0){
        char str[strlen(argv[2])];
        strcpy(str, argv[2]);
        char writeFilename[strlen(argv[4])];
        strcpy(writeFilename,argv[4]);
        char file[strlen(argv[6])];
        strcpy(file,argv[6]);
        char logfile[100];
        for (int i = 0; envp[i] != NULL; i++) {
          if (strncmp(envp[i], "LOGFILENAME", 11) == 0) {
            strcpy(logfile, envp[i]);
            strtok(logfile, "=");
            strcpy(logfile,strtok(NULL, "="));
            getLogFilename(logfile);
            break;
          }
        }

        ChangeToFile(writeFilename, HParser(file,str));
        char strwr[50] = "Analized file ";
        strcat(strwr, file);
        writeToFileV(strwr);

        //FICHEIRO DO -H -O E -V (vai envolver o envp -V)
      }
      else  {
        printf("Wrong parameters");
        return -1;
      }
    }

  }

  else {

    if (argc == 2) {
      char file[strlen(argv[1])];
      strcpy(file,argv[1]);
      printf("%s\n", BasicString(file));
      //FAZER O BÁSICO APENAS
    }

    if (argc == 4) {

      if (strcmp(argv[1], "-h") == 0) {
        char str[strlen(argv[2])];
        strcpy(str, argv[2]);
        char file[strlen(argv[3])];
        strcpy(file,argv[3]);
        printf("%s\n", HParser(file,str));
      }

      else if (strcmp(argv[1], "-o") == 0) {
        char writeFilename[strlen(argv[2])];
        strcpy(writeFilename,argv[2]);
        char file[strlen(argv[3])];
        strcpy(file,argv[3]);

        ChangeToFile(writeFilename, BasicString(file));
        //TODO
        //FAZER APENAS -O
      }

      else if ((strcmp(argv[1], "-r") == 0) && (strcmp(argv[2], "-v") == 0)) {
        char file[strlen(argv[3])];
        strcpy(file,argv[3]);
        char logfile[100];
        for (int i = 0; envp[i] != NULL; i++) {
          if (strncmp(envp[i], "LOGFILENAME", 11) == 0) {
            strcpy(logfile, envp[i]);
            strtok(logfile, "=");
            strcpy(logfile,strtok(NULL, "="));
            getLogFilename(logfile);
            break;
          }
        }

        char *path;
        char actualpath[200];
        path = realpath(file,actualpath);

        if (path) {
          RecursiveHandler(path,false, false, true);
        }
        //FAZER FICHEIRO -R E -V SIMULTANEAMENTE (envolve envp -V)
      }
      else  {
        printf("Wrong parameters");
        return -1;
      }
    }

    else if (argc == 6) {
      if ((strcmp(argv[1], "-h") == 0) && (strcmp(argv[3], "-o") == 0)) {
        char str[strlen(argv[2])];
        strcpy(str, argv[2]);
        char writeFilename[strlen(argv[4])];
        strcpy(writeFilename,argv[4]);
        char file[strlen(argv[5])];
        strcpy(file,argv[5]);

        ChangeToFile(writeFilename, HParser(file,str));

        //FAZER -H E -O

      }
      else if (((strcmp(argv[1], "-r") == 0) && (strcmp(argv[2], "-h") == 0)) && (strcmp(argv[4], "-v") == 0)) {
        getHFlags(argv[3]);
        char file[strlen(argv[5])];
        strcpy(file,argv[5]);

        char logfile[100];
        for (int i = 0; envp[i] != NULL; i++) {
          if (strncmp(envp[i], "LOGFILENAME", 11) == 0) {
            strcpy(logfile, envp[i]);
            strtok(logfile, "=");
            strcpy(logfile,strtok(NULL, "="));
            getLogFilename(logfile);
            break;
          }
        }

        char *path;
        char actualpath[200];
        path = realpath(file,actualpath);

        if (path) {
          RecursiveHandler(path,false, true, true);
        }
      }

      else if (((strcmp(argv[1], "-r") == 0) && (strcmp(argv[2], "-o") == 0)) && (strcmp(argv[4], "-v") == 0)) {
        getFileToWrite(argv[3]);
        char file[strlen(argv[5])];
        strcpy(file,argv[5]);
        char logfile[100];
        for (int i = 0; envp[i] != NULL; i++) {
          if (strncmp(envp[i], "LOGFILENAME", 11) == 0) {
            strcpy(logfile, envp[i]);
            strtok(logfile, "=");
            strcpy(logfile,strtok(NULL, "="));
            getLogFilename(logfile);
            break;
          }
        }

        char *path;
        char actualpath[200];
        path = realpath(file,actualpath);

        if (path) {
          RecursiveHandler(path,true, false, true);
        }

        //FAZER -R -O E -V (usar envp para o -V)

      }
      else  {
        printf("Wrong parameters");
        return -1;
      }
    }

    else  {
      if (((strcmp(argv[1], "-r") == 0) && (strcmp(argv[2], "-h") == 0)) &&(strcmp(argv[4], "-o") == 0) && (strcmp(argv[6], "-v") == 0)) {
        getHFlags(argv[3]);
        getFileToWrite(argv[5]);
        char file[strlen(argv[7])];
        strcpy(file,argv[7]);

        char logfile[100];
        for (int i = 0; envp[i] != NULL; i++) {
          if (strncmp(envp[i], "LOGFILENAME", 11) == 0) {
            strcpy(logfile, envp[i]);
            strtok(logfile, "=");
            strcpy(logfile,strtok(NULL, "="));
            getLogFilename(logfile);
            break;
          }
        }

        char *path;
        char actualpath[200];
        path = realpath(file,actualpath);

        if (path) {
          RecursiveHandler(path,true, true, true);
        }
      }
    }
  }

}
