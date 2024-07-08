// Online C compiler to run C program online
#include<stdio.h>
int p[30],bt[30],tat[30],wt[30],tot_tat=0,tot_wt=0,FCFS_tat=0,FCFS_wt=0,n;
float awt,avg_wt,avg_tat;

void main()
{
    int i;
    printf("Enter the number of process\n");\
    scanf("%d",&n);
    
    printf("Enter the burst time to the process\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    printf("FCFS Algoritham\n");
    WT_TAT(&FCFS_tat,&FCFS_wt);
    
    printf("\n\n Total Turn Around Time:%d",FCFS_tat);
    printf("\n Average Turn Around Time :%d",FCFS_tat/n);
    
    printf("\nTotal Wait Time :%d",FCFS_wt);
    printf("\n Average Wait time:%d",FCFS_wt/n);
    
}

int WT_TAT(int *a, int *b)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(i==0){
            tat[i]=bt[i];
        }
        else{
            tat[i]=tat[i-1]+bt[i];
            tot_tat=tot_tat+tat[i];
            }
            
    }
    *a=tot_tat;
    
    wt[0]=0;
    for(i=0;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tot_wt=tot_wt+wt[i];
    }
    *b=tot_wt;
    
    printf("\nPROCESS\t\tBURST TIME\tTURN AROUND TIME\tWAIT TIME");
    for(i=0;i<n;i++){
    printf("\nPROCESS[%d]\t\t\t%d\t\t\t%d\t\t\t%d",p[i],bt[i],tat[i],wt[i]);
    }
    return(0);
}