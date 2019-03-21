#include "BasicHandler.h"

void getFileInfo(char* filename, char* fileInfo);

char* BasicString(char *filename) {
    struct stat ss;
    int fd1;

    off_t size;
    char modifyDate[20];
    char creationDate[20];
    char* fileInfo= malloc(50);//acertas estes valores
    char* returnString = malloc(200);//não sei se é muito ou pouco
    char comma = ',';
    mode_t permission;
    char permissionOwner[3];
    long c;
    fd1 = open(filename, O_RDWR);

    fstat(fd1, &ss);

    size = ss.st_size; //FILE_SIZE (nao sei porque mas se tiver só 1 caracter aparece que tem 2 e assi por diante!)
    strftime(modifyDate, 20, "%d-%m-%yT%H:%M:%S", localtime(&(ss.st_mtime))); //DATA DE ULTIMA MODIFICAÇAO
    strftime(creationDate, 20, "%d-%m-%yT%H:%M:%S", localtime(&(ss.st_ctime))); //DATA DE CRIACAO

    permission = ss.st_mode;

    if ((permission & S_IRUSR) == 0) {
    }
    else {
        char read[] = "r";
        strcat(permissionOwner, read);
    }

    if ((permission & S_IWUSR) == 0) {
    }
    else {
        char write[] = "w";
        strcat(permissionOwner, write);
    }

    if ((permission & S_IXUSR) == 0) {
    }
    else {
        char execute[] = "x";
        strcat(permissionOwner, execute);
    }

    c = (long) size;

    getFileInfo(filename, fileInfo);
    char* sizeString= malloc(10);
    snprintf(sizeString,10,"%ld",c);

    snprintf(returnString,200,"%s,%s,%s,%s,%s,%s",filename,fileInfo+strlen(filename)+2,sizeString,permissionOwner,creationDate,modifyDate);

    write(STDOUT_FILENO,returnString, 200);//retornar e mvez de escrever no ecra
    return returnString;
    close(fd1);
}


char ChangeToFile(char *filename, char *filename1, char* msg)    // -o
{
    int copy;
    int file = open(filename, O_APPEND | O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    copy = dup(STDOUT_FILENO);

    dup2(file, STDOUT_FILENO);

    close(file);

    //char *msg = "Ola";
    write(STDOUT_FILENO, msg, strlen(msg));

    dup2(copy, STDOUT_FILENO);

    printf("Data saved on file %s\n", filename );
    printf("Execution records saved on file ... \n");

    return 0;
}

void getFileInfo(char* filename, char* fileInfo) {

    int des_p[2];

    if(pipe(des_p) == -1) {
        perror("Pipe failed");
        exit(1);
    }
    int n = fork();
    if(n == 0)            //first fork
    {
        close(STDOUT_FILENO);  //closing stdout
        dup(des_p[1]);         //replacing stdout with pipe write
        close(des_p[0]);       //closing pipe read
        close(des_p[1]);

        char* prog1[] = { "file", filename, 0};
        execvp(prog1[0], prog1);
        perror("execvp of ls failed");
        exit(1);
    }

    if(n > 0) {
        close(STDIN_FILENO);   //closing stdin
        dup(des_p[0]);         //replacing stdin with pipe read
        close(des_p[1]);       //closing pipe write
        close(des_p[0]);
        int n = read(STDIN_FILENO,fileInfo,200);
        fileInfo[n-1] = '\0';
    }

}
