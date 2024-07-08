#include<stdio.h>
#include<unistd.h>
int main(void){

    int pid ,status , exitch;

    if((pid=fork())==-1){
        perror("error");
        exit(0);
    }
    if(pid==0){
        sleep(1);
        printf("Child process");
        exit(0);
    }

    else{
        printf("parent process");
        
        if((exitch==wait(status))==-1){
            perror("During wait()");
            exit(0);
        }
        printf("Parent exixting");
        exit(0);
    }
    return(0);
}