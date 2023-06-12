#include <stdio.h>

void input(int burst[], int arrival[], int n){

    for (int i = 0; i < n; i++)
    {
        int t_burst, t_arrival;
        printf("Enter the Burst Time, Arrival Time for P%d respectively: ", i);
        scanf("%d %d",&t_burst, &t_arrival);
        burst[i] = t_burst;
        arrival[i] = t_arrival;
    }
}

void get_gantt(int arrival[], int burst[], int gantt[], int n){
    int totalTime = 0;
    for (int i = 0; i < n; i++)
    {   
        if(arrival[i] > totalTime){
            totalTime += arrival[i] - totalTime;
        }

        totalTime += burst[i];
        gantt[i] = totalTime;
    }
    
}

void findTurnAround(int gantt[], int arrival[], int turnAround[], int n){
    for (int i = 0; i < n; i++)
    {
        int tat = gantt[i] - arrival[i];
        turnAround[i] = tat;
    }
    
}

void findWaitTime(int turnAround[], int burst[], int waitTime[], int n){
    for (int i = 0; i < n; i++)
    {
        int wat = turnAround[i] - burst[i];
        waitTime[i] = wat;
    }
    
}

// float avg(int arr[], int n){
//     float sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//     }
//     return (sum / n);
// }

int main(){
    printf("How many processes do you want to enter? ");
    int n;
    scanf("%d", &n);

    int burst[n];
    int arrival[n];
    input(burst, arrival, n);

    int gantt[n];
    get_gantt(arrival, burst, gantt, n);

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", gantt[i]);
    // }
    
    int turnAround[n];
    findTurnAround(gantt, arrival, turnAround, n);

    int waitTime[n];
    findWaitTime(turnAround, burst, waitTime, n);

    printf("\nProcess    Burst    Waiting     Turn Around\n");
    float watTotal=0, tatTotal=0;
    for (int i = 0; i < n; i++)
    {
        watTotal = watTotal + waitTime[i];
        tatTotal = tatTotal + turnAround[i];
      printf("%d\t   %d\t    %d     \t%d\n", i, burst[i], waitTime[i], turnAround[i]);
    }
    printf("\nAverage waiting time = %.3f\n", watTotal/n);
    printf("Average turn around time = %.3f\n", tatTotal/n);

    return 0;
}