#include <stdio.h>
#include <stdbool.h>

// Function to check if the requested resources can be allocated
bool isSafe(int available[], int allocation[][3], int max[][3], int process_count) {
    int need[5][3];
    int work[3];
    bool finish[5];
    int safe_sequence[5];
    
    // Initialize the work and finish arrays
    for (int i = 0; i < 3; i++) {
        work[i] = available[i];
    }
    for (int i = 0; i < 5; i++) {
        finish[i] = false;
    }
    
    // Calculate the need matrix
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    
    int count = 0;
    while (count < process_count) {
        bool found = false;
        for (int i = 0; i < process_count; i++) {
            if (finish[i] == false) {
                bool can_allocate = true;
                for (int j = 0; j < 3; j++) {
                    if (need[i][j] > work[j]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    // Allocate resources to process i
                    for (int j = 0; j < 3; j++) {
                        work[j] += allocation[i][j];
                    }
                    safe_sequence[count] = i;
                    finish[i] = true;
                    count++;
                    found = true;
                }
            }
        }
        if (found == false) {
            // No process found that can be allocated resources
            break;
        }
    }
    
    if (count == process_count) {
        // All processes have been allocated resources
        printf("System is in a safe state.\nSafe sequence: ");
        for (int i = 0; i < process_count; i++) {
            printf("P%d ", safe_sequence[i]);
        }
        printf("\n");
        return true;
    } else {
        // Not all processes can be allocated resources
        printf("System is not in a safe state.\n");
        return false;
    }
}

int main() {
    int available[3] = {3, 3, 2};
    int allocation[5][3] = {
        {1, 1, 2},
        {2, 1, 2},
        {4, 0, 1},
        {0, 2, 0},
        {1, 1, 2}
    };
    int max[5][3] = {
        {4, 3, 3},
        {3, 2, 2},
        {9, 0, 2},
        {7, 5, 3},
        {1, 1, 2}
    };
    int process_count = 5;
    
    // Check if the system is in a safe state
    isSafe(available, allocation, max, process_count);
    
    return 0;
}
