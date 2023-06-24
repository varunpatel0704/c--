#include <stdio.h>

int main() {
    int n, i, timeQuantum;
    printf("Name = Varun Patel\nEnrollment No = 211310132001\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int processId[n];
    int burstTime[n];
    int remainingTime[n];
    int turnaroundTime[n];
    int waitingTime[n];

    

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        remainingTime[i] = burstTime[i];
        processId[i] = i;
    }

    int completed = 0;
    int currentTime = 0;

    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                if (remainingTime[i] <= timeQuantum) {
                    currentTime += remainingTime[i];
                    turnaroundTime[i] = currentTime;
                    remainingTime[i] = 0;
                    completed++;
                }

                else {
                    currentTime += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                }
                waitingTime[i] = currentTime - burstTime[i];
            }
        }
    }

    printf("\nProcess    Burst    Waiting     Turn Around\n");


    int watTotal = 0, tatTotal = 0;
    for (int i = 0; i < n; i++)
    {
        watTotal = watTotal + waitingTime[i];
        tatTotal = tatTotal + turnaroundTime[i];
        printf("%d\t   %d\t    %d     \t%d\n",processId[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }
    printf("\nAverage waiting time = %.3f\n", watTotal/n);
    printf("Average turn around time = %.3f\n", tatTotal/n);    

    return 0;
}