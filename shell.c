#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char running = 'y';

void execute(char *path, char **args){
  int pid = fork();
  //Processo filho
  if(pid==0){
      execvp(path,args);
  //Processo Pai
  }else{
      wait(NULL);
      printf("Processo filho terminou execução.\n");
      printf("Quer executar outro comando? (y/n).\n");
      scanf("%c",&running);
      getchar();

  }

}
int main(void)
{
  //Passo 1
  char *command = malloc(256);
  char *argList[256];
  int nmArgs;
  char *path= "/bin/";
  char fullpath[20];
  while(running=='y'){

    printf("Qual vai ser o comando a ser executado?\n");

    //Passo 2
    fgets(command, 256, stdin);
    size_t length = strlen(command);
    if (command[length - 1] == '\n'){
      command[length - 1] = '\0';
    }
    argList[0] = command;
    strcpy(fullpath, path);
    strcat(fullpath, argList[0]);
    // printf("%s aqui", fullpath);

    //Passo 3
    printf("\nOk, vamos executar %s, gostaria de utilzar quantos argumentos?\n", command);
    //Passo 4
    scanf("%d",&nmArgs);

    //Passo 5
    for(int i=0;i<=nmArgs;i++){
      char *arg = malloc(256);
      printf("Diginte o %d argumento.\n", i);
      fgets(arg, 256, stdin);
      size_t length = strlen(arg);
      if (arg[length - 1] == '\n'){arg[length - 1] = '\0';}
      if(i!=0){
        argList[i] = arg;
      }
    }
    argList[nmArgs+1]=NULL;

    //Passo 6
    execute(fullpath,argList);

  }
  return 0;
}
