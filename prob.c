#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char **argv, char **envp) {
  if ((argc < 4) || (argc > 9)) {
    printf("Too many/little arguments!\n");
  }

  else if (argc % 2 == 0) {
    if (argc == 4) {
      //FAZER PARA O -R OU PARA O -V
    }
    else if (argc == 6) {
      //FAZER PARA O -R OU -V
      if (strcmp(argv[2], "-r") == 0) {
        if (strcmp(argv[3], "-h") == 0) {
          char str[strlen(argv[4])];
          strcpy(str, argv[4]);
        }
        else if (strcmp(argv[3], "-o") == 0) {
          char writeFilename[strlen(argv[4])];
          strcpy(writeFilename,argv[4]);
        }
      }
      else if (strcmp(argv[4], "-v") == 0) {
        if (strcmp(argv[2], "-h") == 0) {
          char str[strlen(argv[3])];
          strcpy(str, argv[3]);
        }
        else if (strcmp(argv[2], "-o") == 0) {
          char writeFilename[strlen(argv[3])];
          strcpy(writeFilename,argv[3]);
        }
      }
    }
    else {
      char str[strlen(argv[4])];
      char writeFilename[strlen(argv[6])];
      char fileDirName[strlen(argv[7])];
      strcpy(str, argv[4]);
      strcpy(writeFilename, argv[6]);
      strcpy(fileDirName,argv[7]);
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
