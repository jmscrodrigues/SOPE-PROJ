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
        char file[strlen(argv[3])];
        strcpy(file,argv[3]);
      //TODO
      //FICHEIRO DO -R
    }

      else if (strcmp(argv[2], "-v") == 0) {
        char file[strlen(argv[3])];
        strcpy(file,argv[3]);
        //TODO
        //FICHEIRO DO -V (vai envolver o envp)
      }

      else  {
        printf("Vamos ter que lidar com erro??");
        return -1;
      }

    }

    else if (argc == 6) {
      //FAZER PARA O -R OU -V

      if (strcmp(argv[2], "-r") == 0) {

        if (strcmp(argv[3], "-h") == 0) {
          char str[strlen(argv[4])];
          strcpy(str, argv[4]);
          char file[strlen(argv[5])];
          strcpy(file,argv[5]);
          //TODO
          //FICHEIRO DO -R E -H
        }

        else if (strcmp(argv[3], "-o") == 0) {
          char writeFilename[strlen(argv[4])];
          strcpy(writeFilename,argv[4]);
          char file[strlen(argv[5])];
          strcpy(file,argv[5]);
          //TODO
          //FICHEIRO DO -R E -O
        }
        else  {
          printf("Vamos ter que lidar com erro??");
          return -1;
        }
      }

      else if (strcmp(argv[4], "-v") == 0) {

        if (strcmp(argv[2], "-h") == 0) {
          char str[strlen(argv[3])];
          strcpy(str, argv[3]);
          char file[strlen(argv[5])];
          strcpy(file,argv[5]);
          //TODO
          //FICHEIRO DO -V E -H (vai envolver o envp -V)
        }

        else if (strcmp(argv[2], "-o") == 0) {
          char writeFilename[strlen(argv[3])];
          strcpy(writeFilename,argv[3]);
          char file[strlen(argv[5])];
          strcpy(file,argv[5]);
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

      if (strcmp(argv[2], "-r") == 0) {
        char str[strlen(argv[4])];
        strcpy(str, argv[4]);
        char writeFilename[strlen(argv[6])];
        strcpy(writeFilename,argv[6]);
        char file[strlen(argv[7])];
        strcpy(file,argv[7]);
        //TODO
        //FICHEIRO DO -R -H E -O
    }

      else if (strcmp(argv[6], "-v") == 0){
        char str[strlen(argv[3])];
        strcpy(str, argv[3]);
        char writeFilename[strlen(argv[5])];
        strcpy(writeFilename,argv[5]);
        char file[strlen(argv[7])];
        strcpy(file,argv[7]);
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
    if (argc == 5) {

      if (strcmp(argv[2], "-h") == 0) {
        char str[strlen(argv[3])];
        strcpy(str, argv[3]);
        char file[strlen(argv[4])];
        strcpy(file,argv[4]);
        //TODO
        //FAZER APENAS -H
      }

      else if (strcmp(argv[2], "-o") == 0) {
        char writeFilename[strlen(argv[3])];
        strcpy(writeFilename,argv[3]);
        char file[strlen(argv[4])];
        strcpy(file,argv[4]);
        //TODO
        //FAZER APENAS -O
      }

      else if ((strcmp(argv[2], "-r") == 0) && (strcmp(argv[3], "-v") == 0)) {
        char file[strlen(argv[4])];
        strcpy(file,argv[4]);
        //TODO
        //FAZER FICHEIRO -R E -V SIMULTANEAMENTE (envolve envp -V)
      }
      else  {
        printf("Vamos ter que lidar com erro??");
        return -1;
      }
    }

    else if (argc == 7) {
      if ((strcmp(argv[2], "-h") == 0) && (strcmp(argv[4], "-o") == 0)) {
        char str[strlen(argv[3])];
        strcpy(str, argv[3]);
        char writeFilename[strlen(argv[5])];
        strcpy(writeFilename,argv[5]);
        char file[strlen(argv[6])];
        strcpy(file,argv[6]);
        //TODO
        //FAZER -H E -O

      }
      else if (((strcmp(argv[2], "-r") == 0) && (strcmp(argv[3], "-h") == 0)) && (strcmp(argv[5], "-v") == 0)) {
        char str[strlen(argv[4])];
        strcpy(str, argv[4]);
        char file[strlen(argv[6])];
        strcpy(file,argv[6]);
        //TODO
        //FAZER -R -H E -V (usar envp para o -V)

      }
      else if (((strcmp(argv[2], "-r") == 0) && (strcmp(argv[3], "-o") == 0)) && (strcmp(argv[5], "-v") == 0)) {
        char writeFilename[strlen(argv[4])];
        strcpy(writeFilename,argv[4]);
        char file[strlen(argv[6])];
        strcpy(file,argv[6]);
        //TODO
        //FAZER -R -O E -V (usar envp para o -V)
      }
      else  {
        printf("Vamos ter que lidar com erro??");
        return -1;
      }
    }
    else  {
      if (((strcmp(argv[2], "-r") == 0) && (strcmp(argv[3], "-h") == 0)) &&(strcmp(argv[5], "-o") == 0) && (strcmp(argv[7], "-v") == 0)) {
        char str[strlen(argv[4])];
        strcpy(str, argv[4]);
        char writeFilename[strlen(argv[6])];
        strcpy(writeFilename,argv[6]);
        char file[strlen(argv[8])];
        strcpy(file,argv[8]);
        //TODO
        //FAZER TODOS (usar envp para o -V)

      }
    }
  }

}
