#include<stdio.h>

#define MAX 20
int main()
{
    int bsize[MAX],fsize[MAX],nb,nf;
    int temp,low=10000;
    static int bflag[MAX],fflag[MAX];
    int i,j;
    
    printf("Enter the number of Blocks:\n");
    scanf("%d",&nb);
    
    printf("Enter the size of blocks:\n");
    
    for(i=1;i<=nb;i++)
    {
        printf("Enter the size of %d blocks:",i);
        scanf("%d",&bsize[i]);
    }
    
    printf("Enter the number of files:\n");
    scanf("%d",&nf);
    
    printf("Enter the size of files:\n");
    
    for(i=1;i<=nf;i++)
    {
        printf("Enter the size of %d blocks:",i);
        scanf("%d",&fsize[i]);
    }
    
    printf("\nAllocation using Best fit as foloow\n");
    printf("\nFile no  \t\t File size \t\t block no\t\t block size\n");
    
    for(i=1;i<=nf;i++)
    {
        for(j=1;j<=nb;j++)
        {
            if(bflag[j]!=1){
                temp=bsize[j]-fsize[i];
                if(temp>=0)
                {
                    if(low>temp){
                        fflag[i]=j;
                        low=temp;
                        
                    }
                }
            }
        }
        bflag[fflag[i]]=1;
        low=10000;
    }
for(i=1;i<=nf;i++)
{
    printf("\n\n %d \t\t\t %d \t\t\t %d \t\t\t %d\n",i,fsize[i],fflag[i],bsize[fflag[i]]);
}
}