#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    fork();
    fork();
    fork();
    printf("Helloo Jec\n PID =%d\n",getpid());
    return(0);
}