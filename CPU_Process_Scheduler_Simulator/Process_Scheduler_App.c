#include <stdio.h>  
#define MAX_PROCESSES 100  

// Structure to represent a process
struct Process {
    int id;               // Process ID
    int arrival_time;     // Time when the process arrives
    int burst_time;       // Time required by the process to complete
    int start_time;       // Time when the process starts execution
    int finish_time;      // Time when the process finishes execution
    int waiting_time;     // Time the process waits in the ready queue
    int turnaround_time;  // Total time from arrival to completion
};

// Function to sort the processes by arrival time using simple bubble sort
void sortByArrival(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival_time > p[j].arrival_time) {
                // Swaping the processes
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// Function to simulate First-Come, First-Served (FCFS) scheduling
void simulateFCFS(struct Process p[], int n) {
    sortByArrival(p,n);  // First, sort all processes by their arrival time

    int current_time = 0;  // Keeps track of currnt time during scheduling

    for (int i = 0; i<n; i++) {
        // If CPU is idle, move current_time to the process's arrival time
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;
        }

        // Set start time to current time
        p[i].start_time = current_time;

        // Finish time is start time + burst time
        p[i].finish_time = p[i].start_time + p[i].burst_time;

        // Turnaround time = finish - arrival
        p[i].turnaround_time = p[i].finish_time - p[i].arrival_time;

        // Waiting time = start - arrival
        p[i].waiting_time = p[i].start_time - p[i].arrival_time;

        // Move current time forward
        current_time = p[i].finish_time;
    }
}

// Function to print the final results in a formatted table
void printTable(struct Process p[], int n) {
    printf("ID\tArrival\tBurst\tStart\tFinish\tWaiting\tTurnaround\n");

    for (int i = 0; i <n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].start_time,
               p[i].finish_time,
               p[i].waiting_time,
               p[i].turnaround_time);
    }
}

int main() {
    struct Process p[MAX_PROCESSES];  // Array to hold all process information
    int n;  // Number of processes

    // Get number of processes from user
    printf("Type the number of processes: ");
    scanf("%d", &n);

    // Input arrival time and burst time for each process
    for (int i = 0; i < n;i++) {
        p[i].id = i + 1;  // Assign unique process ID
        printf("Process %d - Arrival Time: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &p[i].burst_time);
    }

    // Perform FCFS scheduling simulation
    simulateFCFS(p, n);

    // Print the scheduling result
    printTable(p, n);

    return 0;
}
