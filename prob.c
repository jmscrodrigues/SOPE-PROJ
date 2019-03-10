#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char **argv, char **envp) {
  if ((argc < 4) || (argc > 9)) {
    printf("Too many/little arguments!\n");
    return -1;
  }
  if (strcmp(argv[1], "forensic") != 0) {
    printf("No 'forensic'\n");
    return -1;
  }

  else if (argc % 2 == 0) {

    if (argc == 4) {
      //FAZER PARA O -R OU PARA O -V

      if (strcmp(argv[2], "-r") == 0) {
      //TODO
      //FICHEIRO DO -R
    }

      else if (strcmp(argv[2], "-v") == 0) {
        //TODO
        //FICHEIRO DO -V
      }

    }

    else if (argc == 6) {
      //FAZER PARA O -R OU -V
      if (strcmp(argv[2], "-r") == 0) {

        if (strcmp(argv[3], "-h") == 0) {
          char str[strlen(argv[4])];
          strcpy(str, argv[4]);
          //TODO
          //FICHEIRO DO -R E -H
        }

        else if (strcmp(argv[3], "-o") == 0) {
          char writeFilename[strlen(argv[4])];
          strcpy(writeFilename,argv[4]);
          //TODO
          //FICHEIRO DO -R E -O
        }
      }

      else if (strcmp(argv[4], "-v") == 0) {

        if (strcmp(argv[2], "-h") == 0) {
          char str[strlen(argv[3])];
          strcpy(str, argv[3]);
          //TODO
          //FICHEIRO DO -V E -H
        }

        else if (strcmp(argv[2], "-o") == 0) {
          char writeFilename[strlen(argv[3])];
          strcpy(writeFilename,argv[3]);
          //TODO
          //FICHEIRO DO -V E -O
        }
      }
    }

    else {
      if (strcmp(argv[2], "-r") == 0) {
        char str[strlen(argv[4])];
        strcpy(str, argv[4]);
        char writeFilename[strlen(argv[6])];
        strcpy(writeFilename,argv[6]);
        //TODO
        //FICHEIRO DO -R -H E -O
    }
      else {
        char str[strlen(argv[3])];
        strcpy(str, argv[3]);
        char writeFilename[strlen(argv[5])];
        strcpy(writeFilename,argv[5]);
        //TODO
        //FICHEIRO DO -H -O E -V
      }
    }
  }

  else {
    if (argc == 5) {
      //VER QUAL E FAZER sem o -r
    }
    else if (argc == 7) {
      //VER QUAIS E FAZER sem o -r
    }
    else  {
      //FAZER TODOS sem o -r
    }
  }

}
