#include <stdio.h>

int main() {
    int n, m; // Number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m], available[m];
    int finished[n]; // Array to keep track of finished processes
    int safeSequence[n]; // Array to store the safe sequence

    // Input Allocation Matrix
    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        finished[i] = 0; // Mark all processes as unfinished initially
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input Max Matrix
    printf("Enter the Max Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j]; // Calculate need matrix
        }
    }

    // Input Available Resources
    printf("Enter the Available Resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    int count = 0; // To count the number of processes in the safe sequence
    while (count < n) {
        int found = 0; // Indicates if a safe process was found in the current pass
        for (int i = 0; i < n; i++) {
            if (finished[i] == 0) { // If process is not finished
                int canProceed = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        canProceed = 0;
                        break;
                    }
                }

                if (canProceed) {
                    // Process i can be completed
                    for (int j = 0; j < m; j++) {
                        available[j] += allocation[i][j];
                    }
                    safeSequence[count++] = i;
                    finished[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) { // No process could be completed
            printf("System is in an unsafe state.\n");
            return 1;
        }
    }

    // If a safe sequence exists
    printf("System is in a safe state.\nSafe Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");

    return 0;
}
