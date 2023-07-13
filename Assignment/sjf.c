#include<stdio.h>
#include<conio.h>
#define max 30

void main(){
    //p is process error
    int i,j,n,t,p[max],bt[max],wt[max],tat[max];
    float awt=0,atat=0;
    printf("Enter no. of process");
    scanf("%d",&n);
    printf("Enter the process number");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter the BT");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    //applying bubble sort to get according to their bt and process p
    for(int i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;

                t=p[j];
                p[j]=p[j+1];
                bt[j+1]=t;
            } 
        }
    }
    printf("Process:\t Burst Time:\t Arrival time:\t Waiting Time:\t Turn around Time:\n");
    for(int i;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        //formula
        for(int j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
        //fix formula
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t %d\t\t %d\t\t  %d\n",p[i],bt[i],wt[i],tat[i]);

    }
    awt=awt/n;
    atat=atat/n;
    printf("Avg WT %f\n",awt);
    printf("Avg TAT %f\n",atat);
    getch();

}