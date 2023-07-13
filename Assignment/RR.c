#include<stdio.h>

#define max 30

int main(){
    int i, n, qt, count = 0, temp, sq = 0;
    int bt[max], wt[max], tat[max], rem_bt[max];
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &qt);

    while(1){
        for(i = 0, count = 0; i < n; i++){
            temp = qt;
            if(rem_bt[i] == 0){
                count++;
                continue;
            }
            if(rem_bt[i] > qt){
                rem_bt[i] = rem_bt[i] - qt;
            }
            else{
                if(rem_bt[i] >= 0){
                    temp = rem_bt[i];
                    rem_bt[i] = 0;
                }
                sq = sq + temp;
                tat[i] = sq;
            }
            if(count == n){
                break;
            }
        }
        if(count == n){
            break;
        }
    }

    printf("Process:\tBurst Time:\tTurnaround Time:\tWaiting Time:\n");
    for(i = 0; i < n; i++){
        wt[i] = tat[i] - bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], tat[i], wt[i]);
    }

    awt = awt / n;
    atat = atat / n;
    printf("\nAverage Waiting Time: %f\n", awt);
    printf("Average Turnaround Time: %f\n", atat);

    return 0;
}
