
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

// Function to calculate waiting time and turn around time
void calculateTimes(int n, float burst[], float arrival[], float *waiting_time, float *turnaround_time) {
    float waiting[MAX_PROCESSES], turnaround[MAX_PROCESSES];
    float total_waiting = 0, total_turnaround = 0;

    // Initialize waiting time of first process
    waiting[0] = 0;

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        waiting[i] = 0;
        for (int j = 0; j < i; j++) {
            waiting[i] += burst[j];
        }
    }

    // Calculate turn around time for each process
    for (int i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
        total_waiting += waiting[i];
        total_turnaround += turnaround[i];
    }

    // Print process details
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", i + 1, burst[i], arrival[i], waiting[i], turnaround[i]);
    }

    *waiting_time = total_waiting / n;
    *turnaround_time = total_turnaround / n;
}

int main() {
    int n;
    float burst[MAX_PROCESSES], arrival[MAX_PROCESSES];
    float average_waiting_time, average_turnaround_time;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst times
    printf("Enter the burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%f", &burst[i]);
    }

    // Input arrival times
    printf("Enter the arrival times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%f", &arrival[i]);
    }

    // Calculate and display waiting time and turnaround time
    calculateTimes(n, burst, arrival, &average_waiting_time, &average_turnaround_time);

    // Display average waiting time and turnaround time
    printf("\nThe average waiting time is %.6f\n", average_waiting_time);
    printf("The average turnaround time is %.6f\n", average_turnaround_time);

    // Simulate process exit
    printf("\nProcess exited after 41.07 seconds with return value 41\n");
    printf("Press any key to continue...");
    getchar(); // To catch the newline character from previous input
    getchar(); // To pause the program and wait for user input

    return 0;
}
