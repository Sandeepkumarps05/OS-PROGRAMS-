#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[]){
    printf("Pid of ex1.c =%d",getpid());
    char *args[]={"hello","JECC","S4ad",NULL};
    execv("./ex2.c",args);
    printf("Back to ex1.c");
    return(0);
}