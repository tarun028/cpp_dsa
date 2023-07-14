#include <stdio.h>

#define max 30

int main() {
    int i, j, n, bt[max], at[max], wt[max], tat[max], temp[max];
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Enter the arrival time: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    temp[0] = 0;

    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;
        temp[i + 1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], wt[i], tat[i]);
    }

    awt = awt / n;
    atat = atat / n;
    printf("Avg WT: %f\n", awt);
    printf("Avg TAT: %f\n", atat);

    return 0;
}
