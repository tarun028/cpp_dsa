#include <iostream>
#include <vector>
#include <algorithm>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
};

bool compareArrivalTime(const Process& p1, const Process& p2) {
    return p1.arrivalTime < p2.arrivalTime;
}

int main() {
    int n; // number of processes
    std::cout << "Enter the number of processes: ";
    std::cin >> n;

    std::vector<Process> processes(n);

    // Input process details
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        std::cout << "Enter arrival time for process " << i + 1 << ": ";
        std::cin >> processes[i].arrivalTime;
        std::cout << "Enter burst time for process " << i + 1 << ": ";
        std::cin >> processes[i].burstTime;
    }

    // Sort processes by arrival time
    std::sort(processes.begin(), processes.end(), compareArrivalTime);

    int currentTime = 0;
    double highestResponseRatio = 0.0;
    int processIndex = 0;

    for (int i = 0; i < n; ++i) {
        int remainingTime = processes[i].burstTime;

        // Calculate the response ratio for each process
        double responseRatio = (currentTime - processes[i].arrivalTime + remainingTime) / static_cast<double>(remainingTime);

        if (responseRatio > highestResponseRatio) {
            highestResponseRatio = responseRatio;
            processIndex = i;
        }

        // Update the current time
        currentTime += processes[i].burstTime;

        // Calculate completion time, turnaround time, waiting time, and response time
        processes[i].completionTime = currentTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
        processes[i].responseTime = processes[i].waitingTime;
    }

    // Print the results
    std::cout << "\nProcess\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n";
    for (const Process& p : processes) {
        std::cout << p.id << "\t\t" << p.completionTime << "\t\t" << p.turnaroundTime << "\t\t"
            << p.waitingTime << "\t\t" << p.responseTime << std::endl;
    }

    return 0;
}
