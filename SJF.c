#include<stdio.h>

void main(){
    int n,i,b,j;
    printf("Enter the no:of tasks\n");
    scanf("%d",&n);
    int wt[n],exe[n];
    int tat[n];
    float awt=0;
    wt[0]=0;
    printf("Enter the burst times\n ");
    for ( i = 0; i <n; i++)
    {
        scanf("%d",&exe[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(exe[i]>exe[j])
            {
                b=exe[i];
                exe[i]=exe[j];
                exe[j]=b;
            }
        }
    }

    for ( i = 1; i <n; i++)
    {
        wt[i]=wt[i-1]+exe[i-1];
    }
    printf("Task\tWaiting Time\n");
    for( i = 0; i <n; i++)
    {
        printf("p[%d] = \t%d\n",i+1,wt[i]);
    }
    printf("\nTask\tTurnaround time.......\n");
    for( i = 0; i < n; i++)
    {
        printf("p[%d] = \t%d\n",i+1,wt[i]+exe[i]);
    }
    
 for ( i = 0; i <n; i++)
    {
        awt=awt+wt[i];
    }
    awt=awt/n;
    printf("Average Waiting time=%f",awt);

}
