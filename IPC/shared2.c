#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>

#define SHMSZ 27
int main(){
    int shmid;
    key_t key;
    char *shm,*s;
    key=5678;

    if((shmid=shmget(key,SHMSZ,IPC_CREAT|0666))<0){
        perror("shmget");
        exit(1);
    }

    if((shm=shmat(shmid,NULL,0))==(char*)-1){
        perror("shmat");
        exit(1);

    }
    for(s=shm;*s!='\0';s++){
        putchar(*s);
        putchar('\n');
        *shm='*';
    }

    if(shmdt(shm)==-1){
        perror("shmdt");
        exit(1);

    }
    return(0);
}

