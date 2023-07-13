#include<stdio.h>
#include<conio.h>
#define max 30

void main(){
    int i,j,n,bt[max],at[max],wt[max],tat[max],temp[max];
    float awt=0, atat=0;
    //clrscr();
    printf("Enter number of processes");
    scanf("%d",&n);
    printf("Enter BT");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    printf("Enter AT");
    for(int i=0;i<n;i++){
        scanf("%d",&at[i]);
    }
    temp[0]=0;

    printf("Process\t Burst Time\t Arrival time\t Waiting Time\t Turn around Time\n");

    for(int i;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        //formula
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-at[i];
        //fix formula
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],at[i],wt[i],tat[i]);

    }
    awt=awt/n;
    atat=atat/n;
    printf("Avg WT %f\n",awt);
    printf("Avg TAT %f\n",atat);
    getch();
}