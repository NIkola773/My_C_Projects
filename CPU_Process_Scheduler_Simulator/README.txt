FCFS CPU Scheduling Simulator (C Language)

This is a simple C program that simulates the **First-Come, First-Served (FCFS)** 
CPU scheduling algorithm. It accepts information about multiple processes (arrival time and burst time), 
then calculates  and displays the start time, finish time, waiting time, and turnaround time for  each process .

Features:

- Accepts up to 100 processes
- Sorts processes by arrival time
- Simulates FCFS scheduling
- Displays a detailed process table including:
  - Process ID
  - Arrival Time
  - Burst Time
  - Start Time
  - Finish Time
  - Waiting Time
  - Turnaround Time


Example Input:


Type the number of processes: 3
Proces 1 - Arrival Time: 0
Proces 1 - Burst time: 5
Proces 2 - Arrival Time: 2
Proces 2 - Burst time: 3
Proces 3 - Arrival Time: 4
Proces 3 - Burst time: 1

Output:


ID	Arrival	Burst	Start	Finish	Waiting	Turnaround
1	0	    5	    0	    5	    0	    5
2	2	    3	    5	    8	    3	    6
3	4	    1	    8	    9	    4	    5


