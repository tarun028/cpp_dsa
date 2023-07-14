#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    float response_ratio;
};

void hrrn_scheduling(struct Process processes[], int n) {
    int current_time = 0;
    int completed = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    while (completed < n) {
        float max_response_ratio = -1;
        int selected_index = -1;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].response_ratio == -1) {
                float response_ratio = (current_time - processes[i].arrival_time + processes[i].burst_time) / (float)processes[i].burst_time;
                if (response_ratio > max_response_ratio) {
                    max_response_ratio = response_ratio;
                    selected_index = i;
                }
            }
        }

        if (selected_index == -1) {
            current_time += 1;
        } else {
            struct Process* selected_process = &processes[selected_index];
            selected_process->response_ratio = max_response_ratio;
            selected_process->completion_time = current_time + selected_process->burst_time;
            selected_process->turnaround_time = selected_process->completion_time - selected_process->arrival_time;
            selected_process->waiting_time = selected_process->turnaround_time - selected_process->burst_time;

            total_waiting_time += selected_process->waiting_time;
            total_turnaround_time += selected_process->turnaround_time;

            completed += 1;
            current_time = selected_process->completion_time;  // Update current_time to completion time
        }
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("Process\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\n");
    for (int i = 0; i < n; i++) {
        struct Process process = processes[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process.pid, process.arrival_time, process.burst_time, process.completion_time, process.turnaround_time, process.waiting_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    // Define the processes with their arrival time and burst time
    struct Process processes[] = {
        {0, 0, 3, 0, 0, 0, -1},
        {1, 2, 6, 0, 0, 0, -1},
        {2, 4, 4, 0, 0, 0, -1},
        {3, 6, 5, 0, 0, 0, -1},
        {4, 8, 2, 0, 0, 0, -1}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    // Run the HRRN scheduling algorithm
    hrrn_scheduling(processes, n);

    return 0;
}
