#include<stdio.h>
#include<stdlib.h>

int main(){
    int RQ[100],i,n,initial,TotalHeadMovement;
    
    printf("Enter the number of requests:");
    scanf("%d",&n);
    
    printf("\nEnter the Request sequence:");
    for(i=0;i<n;i++){
        scanf("%d",&RQ[i]);
        
    }
    
    printf("\nEnter the initial head movement:");
    scanf("%d",&initial);
    
    for(i=0;i<n;i++){
        TotalHeadMovement+=abs(RQ[i]-initial);
        initial=RQ[i];
    }
    printf("\nTotal Head movement=%d",TotalHeadMovement);
    return(0);
}