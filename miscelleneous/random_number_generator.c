#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int rand_num,i=0;
    srand(time(0));//--> returns time in seconds
    printf("\n%d is the initialized value",rand_num);
    while(i<10){
    
    rand_num=rand()%100+1;//Generates random number b/w 1 to 100.
    printf("\nThe number generated is: %d",rand_num);
    i++;
    }
    
    return 0;
}