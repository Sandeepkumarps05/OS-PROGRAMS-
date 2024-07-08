// Online C compiler to run C program online
#include<stdio.h>
int need[100][100];
int max[100][100];
int alloc[100][100];
int avail[100];
int need[100][100];
int n,r;
void input();
void show();
void cal();

int main(){
    printf("Bankers Algoritham\n");
    input();
    show();
    cal(); 
    return(0);
}
void  input(){
     int i,j;
    
    printf("Enter the number of process:");
    scanf("%d",&n);
    
    printf("\nEnter the number of resourece instance:");
    scanf("%d",&r);
    
    printf("\nEnter the MAX matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    
     printf("\nEnter the Allocation matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    
    printf("\nEnter the available resouces:\n");
    for(j=0;j<r;j++)
    {
        scanf("%d",&avail[j]);
    }
}

void show(){
    int i,j;
    
    printf("\n\n PROCESS \t\t ALLOCATION \t\t MAX \t\t AVAILABLE \t\tNEED");
    
    
    for(i=0;i<n;i++)
    {
        
        printf("\nP%d\t",i+1);
            for(j=0;j<r;j++)
            {
                printf("%d",alloc[i][j]);
            }
   
        printf("\t\t\t\t");
    
     
        for(j=0;j<r;j++)
        {
            printf("%d",max[i][j]);
        }
    
        printf("\t\t\t\t");
        
        if(i==0)
        {
             for(j=0;j<r;j++)
            {
                printf("%d",avail[j]);
             }
        }
    }
}

void cal()
{
    
    int i,j,finish[100],temp,flag=1,safe[100],k,c1=0,c=0;;
    
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    //need matrix
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("\n");
    while(flag){
        flag=0;
        for(i=0;i<n;i++)
        {
           
            for(j=0;j<r;j++){
                if((finish[i]==0)&&(need[i]<=avail[j])){
                    c++;
                    if(c==r){
                        for(k=0;k<r;k++){
                            avail[k]+=alloc[i][j];
                            finish[i]=1;
                            flag=1;
                        }
                        printf("P%d->",i);
                        if(finish[i]==1){
                            i=n;
                        }
                    }
                }
                
            }
        }
    }
    
   for(i=0;i<n;i++){
       if(finish[i]==1){
           c1++;
       }
       else{
           printf("P%d->",i);
       }
   }
   if(c1==n){
       printf("\nProcess is in deadlock\n");
       printf("\n System is not in safe state");
   }
   else{
       printf("\nSystem is in safe state\n");
       
   }
}