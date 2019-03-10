#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXH 15


int main(int argc, char **argv, char **envp) {
  if (argc < 3 || argc > 9) {
    printf("Too many/little arguments!\n");
  }

  else if (((argc % 2 != 0) && (strcmp(argv[2], "-r") != 0))  || ((argc %2 == 0) && (strcmp(argv[2], "-r") == 0))) {
    printf("You forgot/added an argument!\n");
  }

  else if (argc % 2 != 0) {
    if (argc == 3) {
      //FAZER PARA O -R
    }
    else if (argc == 5) {
      //FAZER PARA TODOS OS FICHEIROS E REPOSITORIOS COM A CONFIGURAÇÃO SEGUINTE:
      if (strcmp(argv[3], "-h") == 0) {
        char str[MAXH];
        strcpy(str, argv[4]);
      }
    }
    else if (argc == 7) {
      //VER QUAIS SAO
    }
    else {
      //FAZER TODOS
    }
  }

  else {
    if (argc == 4) {
      //VER QUAL E FAZER sem o -r
    }
    else if (argc == 6) {
      //VER QUAIS E FAZER sem o -r
    }
    else  {
      //FAZER TODOS sem o -r
    }
  }

}
