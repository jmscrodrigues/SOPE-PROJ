#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BasicHandler.h"
#include "VHandler.h"
#include "RHandler.h"


int main(int argc, char **argv, char **envp) {

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
        DIR *dir = opendir(file);
        if(dir != NULL) {
          RecursiveHandler(dir, false, false, false);
        }
        else {
          printf("Not a directory!");
        }
      //TODO
      //FICHEIRO DO -R
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
        BasicString(file);
        strcpy(event, "Analized file ");
        strcat(event, file);
        writeToFileV(event);
        //TODO
        //FICHEIRO DO -V (vai envolver o envp)
      }

      else  {
        printf("Vamos ter que lidar com erro??");
        return -1;
      }

    }

    else if (argc == 5) {
      //FAZER PARA O -R OU -V

      if (strcmp(argv[1], "-r") == 0) {

        if (strcmp(argv[2], "-h") == 0) {
          char str[strlen(argv[3])];
          strcpy(str, argv[3]);
          char file[strlen(argv[4])];
          strcpy(file,argv[4]);
          //TODO
          //FICHEIRO DO -R E -H
          // PRINTF BASICHANDLER
        }

        else if (strcmp(argv[2], "-o") == 0) {
          char writeFilename[strlen(argv[3])];
          strcpy(writeFilename,argv[3]);
          char file[strlen(argv[4])];
          strcpy(file,argv[4]);
          //TODO
          //FICHEIRO DO -R E -O
        }
        else  {
          printf("Vamos ter que lidar com erro??");
          return -1;
        }
      }

      else if (strcmp(argv[3], "-v") == 0) {

        if (strcmp(argv[1], "-h") == 0) {
          char str[strlen(argv[2])];
          strcpy(str, argv[2]);
          char file[strlen(argv[4])];
          strcpy(file,argv[4]);
          //TODO
          //FICHEIRO DO -V E -H (vai envolver o envp -V)
        }

        else if (strcmp(argv[1], "-o") == 0) {
          char writeFilename[strlen(argv[2])];
          strcpy(writeFilename,argv[2]);
          char file[strlen(argv[4])];
          strcpy(file,argv[4]);
          //TODO
          //FICHEIRO DO -V E -O (vai envolver o envp -V)
        }

        else  {
          printf("Vamos ter que lidar com erro??");
          return -1;
        }
      }
    }

    else {

      if (strcmp(argv[1], "-r") == 0) {
        char str[strlen(argv[3])];
        strcpy(str, argv[3]);
        char writeFilename[strlen(argv[5])];
        strcpy(writeFilename,argv[5]);
        char file[strlen(argv[6])];
        strcpy(file,argv[6]);
        //TODO
        //FICHEIRO DO -R -H E -O
    }

      else if (strcmp(argv[5], "-v") == 0){
        char str[strlen(argv[2])];
        strcpy(str, argv[2]);
        char writeFilename[strlen(argv[4])];
        strcpy(writeFilename,argv[4]);
        char file[strlen(argv[6])];
        strcpy(file,argv[6]);
        //TODO
        //FICHEIRO DO -H -O E -V (vai envolver o envp -V)
      }
      else  {
        printf("Vamos ter que lidar com erro??");
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
        //TODO
        //FAZER APENAS -H
      }

      else if (strcmp(argv[1], "-o") == 0) {
        char writeFilename[strlen(argv[2])];
        strcpy(writeFilename,argv[2]);
        char file[strlen(argv[3])];
        strcpy(file,argv[3]);

        printf("%s\n", BasicString(file));
        ChangeToFile(writeFilename, file, BasicString(file));
        //TODO
        //FAZER APENAS -O
      }

      else if ((strcmp(argv[1], "-r") == 0) && (strcmp(argv[2], "-v") == 0)) {
        char file[strlen(argv[3])];
        strcpy(file,argv[3]);
        //TODO
        //FAZER FICHEIRO -R E -V SIMULTANEAMENTE (envolve envp -V)
      }
      else  {
        printf("Vamos ter que lidar com erro??");
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
        //TODO
        //FAZER -H E -O

      }
      else if (((strcmp(argv[1], "-r") == 0) && (strcmp(argv[2], "-h") == 0)) && (strcmp(argv[4], "-v") == 0)) {
        char str[strlen(argv[3])];
        strcpy(str, argv[3]);
        char file[strlen(argv[4])];
        strcpy(file,argv[5]);
        //TODO
        //FAZER -R -H E -V (usar envp para o -V)

      }
      else if (((strcmp(argv[1], "-r") == 0) && (strcmp(argv[2], "-o") == 0)) && (strcmp(argv[4], "-v") == 0)) {
        char writeFilename[strlen(argv[3])];
        strcpy(writeFilename,argv[3]);
        char file[strlen(argv[5])];
        strcpy(file,argv[5]);
        //TODO
        //FAZER -R -O E -V (usar envp para o -V)
      }
      else  {
        printf("Vamos ter que lidar com erro??");
        return -1;
      }
    }
    else  {
      if (((strcmp(argv[1], "-r") == 0) && (strcmp(argv[2], "-h") == 0)) &&(strcmp(argv[4], "-o") == 0) && (strcmp(argv[6], "-v") == 0)) {
        char str[strlen(argv[3])];
        strcpy(str, argv[3]);
        char writeFilename[strlen(argv[5])];
        strcpy(writeFilename,argv[5]);
        char file[strlen(argv[7])];
        strcpy(file,argv[7]);
        //TODO
        //FAZER TODOS (usar envp para o -V)

      }
    }
  }

}

// -r vai ter que verificar se o opendir() funciona
// Caso nao funcione, trata como um ficheiro normal (só para fazer alguma cena, pode sempre retornar-se um erro)
// Caso funcione e abra o diretorio:
// Processo pai analisa o 1º ficheiro, chamando o fork() (processo(s) filho) para repetir a ação do processo pai
// Nota: NO proj.c (se -v enabled) criar sempre uma string quando se cria processo filho e analisa FICHEIRO
// (se -o enabled) criar uma string quando escreve, se ambos enabled, fazer os 2
// -r tem que receber 2 boolean, 1 para o -o e outro para o -v, as funções tem que ser chamadas durante os processos
