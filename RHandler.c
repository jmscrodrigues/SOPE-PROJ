#include "RHandler.h"

void RecursiveHandler(DIR *dir, bool oFlag, bool hFlag, bool vFlag) {

  struct dirent *dt;

  dt = readdir(dir);
  while (dt != NULL) {

    int pid = fork();

    if (pid == 0) {
      if (dt->d_type== DT_REG) {
        printf("File: %s\n", dt->d_name);
        //VERIFICAR CONDIÇOES E FAZER AS COISAS
      }
      else {
        DIR* d = opendir(dt->d_name);
        printf("Dir: %s\n", dt->d_name);
        RecursiveHandler(d, oFlag, hFlag, vFlag);
        closedir(d);  //ISTO VAI TER QUE SE RETIRAR, ACHO, PORQUE ELE JA DA CLOSE QUANDO ACABA O DIRETORIO EM SI! NO ENTANTO SE FOR RETIRADO AGORA, ESTOIRA O PC
      }

    }

  //  dt = readdir(dir);  ISTO ACHO QUE TEM QUE SE ADICIONAR MAS SE SE ADICIONAR AGORA, ESTOIRA O PC TAMBEM :|

    /*
    if (hFlag && vFlag && oFlag) {
      //DO 1
    }

    else if (hFlag && vFlag) {
      //DO 2
    }

    else if (hFlag && oFlag) {
      //DO 3
    }

    else if (oFlag && vFlag) {
      //DO 4
    }

    else if (hFlag) {
      //DO 5
    }

    else if (oFlag) {
      //DO 6
    }

    else if (vFlag) {
      //DO 7
    }*/

  }

  closedir(dir);

}
