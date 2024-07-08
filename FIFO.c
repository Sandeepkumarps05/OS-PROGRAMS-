#include<stdio.h>

int main(){
    int i,j,k,count=0,avail,nf,n,p[50],frame[10];
    
    printf("Enter the number of pages:");
    scanf("%d",&n);
    
    printf("\nEnter the elements to the pages:\n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    
    printf("\nEnter the number of frames:");
    scanf("%d",&nf);
    
    for(i=0;i<n;i++)
        frame[i]=-1;
        j=0;
        printf("\n process \t\t\tref string \t\t Page \t\t Frame\n");
    for(i=0;i<n;i++){
        printf("\t\t%d\t\t",p[i]);
        avail=0;
        for(k=0;k<nf;k++)
           if(frame[k]==p[i])
               avail=1;
               if(avail==0){
                   frame[j]=p[i];
                   j=(j+1)%nf;
                   count++;
               }
                   for(k=0;k<nf;k++){
                       printf("\t\t%d\t",frame[k]);
                 
               }
               printf("\n");
           
          
        
    }
     printf("page fault is %d ",count);
    return(0);
    
}