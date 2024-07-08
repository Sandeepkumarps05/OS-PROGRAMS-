#include<stdio.h>
int p[30],bt[30],pr[30],tat[30],wt[30],tot_tat=0,tot_wt,PR_tat=0,PR_wt=0,n;
float awt,avg_tat,avg_wt;

void main()
{
    int i;
    printf("Enter the number of process\n");
    scanf("%d",&n);
     for(i=0;i<n;i++)
    {
        printf("Enter the burst timecand Priotity of [%d]:\n",i+1);
        scanf("%d %d",&bt[i],&pr[i]);
        p[i]=i;
    }

    sort();
    WT_TAT(&PR_tat,&PR_wt);

    printf("\n\nTotal Turn Around Time:%d\n",PR_tat);
    printf("\n\nAverage Turn Around Time:%d\n",PR_tat/n);
    printf("\n\nTotal Wait Time:%d\n",PR_wt);
    printf("\n\nAverage Wait Time:%d\n",PR_wt/n);
    
}

int sort()
{
    int i,j,t,t1,t2;
    for(i=0;i<n;i++)
    {
        for(j=1+i;j<n;j++)
        {
                if(pr[i]>pr[j]){
                    swap(&bt[j],&bt[i]);
                     swap(&p[j],&p[i]);
                    swap(&pr[j],&pr[i]);
                }
        }
    }
    return(0);
}

int swap(int *a,int *b)
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

    
    printf("\n\nPROCESS\t\tBURST TIME \tPROIRITY\t TURN AROUND TIME\t WAIT TIME ");
    for(i=0;i<n;i++)
    {
        printf("\n\nPROCESS[%d],\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",p[i]+1,bt[i],pr[i],tat[i],wt[i]);

    }
    return(0);
}