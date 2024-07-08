#include<stdio.h>
int p[30],bt[30],n,tat[30],wt[30],tot_tat=0,tot_wt=0,SJF_tat=0,SJF_wt=0;
float awt , avg_tat, avg_wt;

void main()
{
    int i;
    printf("Enter the number of process\n");
    scanf("%d",&n);
    
    printf("Enter the burst time for the process\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    sort();
    WT_TAT(&SJF_tat,&SJF_wt);
    
    printf("\n Total Turn Around Time:%d",SJF_tat);
    printf("\n Average time:%d",SJF_tat/n);
    printf("\n Total wait Time:%d",SJF_wt);
    printf("\n Average Wait time:%d",SJF_wt/n);
}

int sort(){
    int t,i,j;
    for(i=0;i<n;i++)
    {
        for(j=1+i;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                swap(&bt[j],&bt[i]);
                swap(&p[j],&p[i]);
            }
        }
    }
    return(0);
}

int swap(int *a , int *b)
{
    int t;
    t=*a;
    *a=*b; 
    *b=t;

return(0);
}

int WT_TAT(int *a,int *b)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            tat[i]=bt[i];
        }
        else{
            tat[i]=tat[i-1]+bt[i];
            tot_tat=tot_tat+tat[i];
        }
    }
    *a=tot_tat;
    
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tot_wt=tot_wt+wt[i];
    }
    *b=tot_wt;
    
   printf("\n\n PROCESS \t BURST TIME \t TURN AROUND TIME \t WAIT TIME");
    for(i=0;i<n;i++)
    {
    printf("\n PROCESS[%d]\t\t\t%d\t\t\t%d\t\t\t%d",p[i]+1,bt[i],tat[i],wt[i]);
    }
    return(0);
}