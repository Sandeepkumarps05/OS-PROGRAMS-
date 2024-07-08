#include<stdio.h>
struct process{
    int ps;
    int flag;
}p[50];
struct sizes{
    int size;
    int alloc;
}s[5];

int main(){
    int i,j,np=0,nb=0;
    
    
    
    printf("Enter the number of blocks:");
    scanf("%d",&nb);
    
    printf("\nEnter the size of %d Block\n :",nb);
    for(i=0;i<nb;i++)
    {
        printf("Enter the size of %d block :",i);
        scanf("%d",&s[i].size);
    }
    
     printf("Enter the number of process:");
    scanf("%d",&np);
    
    printf("\nEnter the size of %d process :",np);
    for(i=0;i<np;i++)
    {
        printf("Enter the size of %d process :",i);
        scanf("%d",&p[i].ps);
    }
   
    printf("Allocation using First fit as follow");
    printf("\nProcess \t\t Process size \t\t Block size\n");
    
    for(i=0;i<np;i++){
        for(j=0;j<nb;j++)
        {
            if(p[i].flag!=1){
                if(p[i].ps<=s[j].size){
                    if(!s[j].alloc){
                        p[i].flag=1;
                        s[j].alloc=1;
                        
                        printf("\n%d\t\t\t\t%d\t\t\t\t%d\n",i,p[i].ps,s[j].size);
                    }
                }
            }
        }
    }
    for(i=0;i<np;i++)
    {
    if(p[i].flag!=1)
    {
        printf("soryyy ,%d");
    }
        
    }
}