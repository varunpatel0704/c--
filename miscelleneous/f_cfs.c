#include <stdio.h>

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main() {
    int n;
    printf("Name = Varun Patel\nEnrollment No = 211310132001\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burstTime[n], process[n];
    int waitTime[n], turnAroundTime[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Burst time for process P%d: ", i);
        scanf("%d", &burstTime[i]);
        process[i] = i;
    }

    // Sort the processes based on burst time using bubble sort
    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = 0; j < n-i-1; j++)
    //     {
    //         if(burstTime[j] > burstTime[j+1]){
    //             swap(burstTime, j, j+1);
    //             swap(process, j, j+1);
    //         }
                
    //     }
        
    // }
    waitTime[0] = 0;

    for (int i = 1; i < n; i++) {
        waitTime[i] = waitTime[i - 1] + burstTime[i - 1];
    }

    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = waitTime[i] + burstTime[i];
    }
    printf("\nProcess    Burst    Waiting     Turn Around\n");


    float watTotal = 0, tatTotal = 0;
    for (int i = 0; i < n; i++)
    {
        watTotal = watTotal + waitTime[i];
        tatTotal = tatTotal + turnAroundTime[i];
        printf("%d\t   %d\t    %d     \t%d\n", process[i], burstTime[i], waitTime[i], turnAroundTime[i]);
    }
    printf("\nAverage waiting time = %.3f\n", watTotal/n);
    printf("Average turn around time = %.3f\n", tatTotal/n);    
    return 0;
}