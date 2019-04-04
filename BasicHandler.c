#include "BasicHandler.h"

char* BasicString(char *filename) {
    struct stat ss;
    int fd1;

    off_t size;
    char modifyDate[50];
    char creationDate[50];
    char* fileInfo= calloc(MAX_SIZE, 1);//acertas estes valores
    char* returnString = calloc(MAX_SIZE,1);//não sei se é muito ou pouco
    char comma = ',';
    mode_t permission;
    char permissionOwner[5];
    long c;

    char * defFile =  calloc(200, 1);

    if (strchr(filename, '/') == NULL) {
      strcpy(defFile, filename);
    }
    else{
      strcpy(defFile, strrchr(filename, '/'));
      defFile+=1;
    }

    fd1 = open(filename, O_RDWR);

    fstat(fd1, &ss);

    size = ss.st_size; //FILE_SIZE (nao sei porque mas se tiver só 1 caracter aparece que tem 2 e assi por diante!)
    strftime(modifyDate, 50, "%y-%m-%dT%H:%M:%S", localtime(&(ss.st_mtime))); //DATA DE ULTIMA MODIFICAÇAO
    strftime(creationDate, 50, "%y-%m-%dT%H:%M:%S", localtime(&(ss.st_ctime))); //DATA DE CRIACAO

    permission = ss.st_mode;

    char not[] = "-";
    if ((permission & S_IRUSR) == 0) {
      strcat(permissionOwner, not);
    }
    else {
        char read[] = "r";
        strcat(permissionOwner, read);
    }

    if ((permission & S_IWUSR) == 0) {
      strcat(permissionOwner, not);
    }
    else {
        char write[] = "w";
        strcat(permissionOwner, write);
    }

    if ((permission & S_IXUSR) == 0) {
      strcat(permissionOwner, not);
    }
    else {
        char execute[] = "x";
        strcat(permissionOwner, execute);
    }

    c = (long) size;

    char* fileCommand[] = { "file", filename, 0};
    getExternalCommand(filename, fileInfo,fileCommand);
    char* sizeString= calloc(10,1);
    snprintf(sizeString,10,"%ld",c);

    snprintf(returnString,4096,"%s,%s,%s,%s,%s,%s",defFile,fileInfo+strlen(filename)+2,sizeString,permissionOwner,creationDate,modifyDate);

    close(fd1);

    free(fileInfo);

    return returnString;
}


char ChangeToFile(char *filename, char* msg)    // -o
{
    int copy;
    int file = open(filename, O_APPEND | O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    copy = dup(STDOUT_FILENO);

    dup2(file, STDOUT_FILENO);

    close(file);

    //char *msg = "Ola";
    write(STDOUT_FILENO, msg, strlen(msg));
    write(STDOUT_FILENO, "\n", 1);

    dup2(copy, STDOUT_FILENO);

    printf("Data saved on file %s\n", filename );
    printf("Execution records saved on file ... \n");

    return 0;
}

void getExternalCommand(char* filename, char* outPutStr, char* commands[]) {

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

        execvp(commands[0], commands);
        perror("execvp failed");
        exit(1);
    }

    if(n > 0) {
        close(STDIN_FILENO);   //closing stdin
        dup(des_p[0]);         //replacing stdin with pipe read
        close(des_p[1]);       //closing pipe write
        close(des_p[0]);
        int n = read(STDIN_FILENO,outPutStr,200);
        outPutStr[n-1] = '\0';
    }
}

char* HParser(char* filename, char* type) {

    char returnStr[3][200];
    char delim[] = ",";
    char typeArray[3][10]; //array com os comandos a executar
    int counter = -1;
    char * basic= malloc(MAX_SIZE);

    if(strstr(type,"sha256")!=NULL) {
        counter++;
        strcpy(typeArray[counter],"sha256sum");
    }
    if(strstr(type,"sha1")!=NULL) {
        counter++;
        strcpy(typeArray[counter],"sha1sum");
    }
    if(strstr(type,"md5")!=NULL) {
        counter++;
        strcpy(typeArray[counter],"md5sum");
    }

    strcpy(basic, BasicString(filename));

    int icount = 0;

    while(icount <= counter) {
        char* command[] = {typeArray[icount], filename,0};
        getExternalCommand(filename,returnStr[icount],command);
       /* write(STDOUT_FILENO,typeArray[icount],strlen(typeArray[icount]));
        write(STDOUT_FILENO," ",1);
        write(STDOUT_FILENO,filename,strlen(filename));
        write(STDOUT_FILENO,"\n",1);*/ // Apagar eventualmente
        icount++;
    }

    icount = 0;

    char* rt = calloc(512, 1);
     while(icount <= counter) {
        strcpy(returnStr[icount],strtok(returnStr[icount], " "));
        strcat(rt,returnStr[icount]);
        strcat(rt,",");
        icount++;
    }
    rt[strlen(rt)-1] = '\0';
    //printf("%s",rt);

    strcat(basic,",");
    strcat(basic, rt);

    return basic;
}
