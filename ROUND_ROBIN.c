#include<stdio.h>

int TRUE=0;
int FALSE=-1;

int bt[30],tbt[30],qt=0,n,tqt=0,lmore,time=0,t_tat=0,t_wt=0,tat[30],wt[30];

void main()
{
    int i;
    printf("Enter the number of process:");
    scanf("%d",&n);
    
    printf("Enter the quantum time for the process:");
    scanf("%d",&qt);
    
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time for the process [%d]:",i+1);
        scanf("%d",&bt[i]);
        
        tbt[i]=bt[i];
        wt[i]=tat[i]=0;
    }
    
    lmore =TRUE;
    while(lmore==TRUE){
        lmore=FALSE;
        for(i=0;i<n;i++)
        {
            if(bt[i]!=0)
            wt[i]=wt[i]+(time-tat[i]);
            tqt=1;
            
            while(tqt<=qt &&  bt[i]!=0)
            {
                lmore=TRUE;
                bt[i]=bt[i]-1;
                tqt++;
                time++;
                tat[i]=time;
            }
        }
    }
    
    printf("\n PROCESS \t\t BURST TIME \t TURN AROUND TIME \t WAIT TIME \n");
    for(i=0;i<n;i++)
    {
        printf("PROCESS[%d]\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n",i+1,tbt[i],tat[i],wt[i]);
        
        t_tat=t_tat+tat[i];
        t_wt=t_wt+wt[i];
    }
    
    
    printf("\n\n Total Turn Around Time :%d",t_tat);
    printf("\n Average Turn Around Time :%d",t_tat/n );
    printf("\n Total Wait Time :%d",t_wt);
    printf("\n Average Wait Time :%d",t_wt/n );
    
}