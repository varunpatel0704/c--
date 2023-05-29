#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int randnum, guess, attempts = 1;
    randnum = rand() % 100 + 1;
    do
    {   
        printf("\n\nEnter your guess: ");
        scanf("%d", &guess);
        
        if(guess>randnum){
            printf("\nLower number please!");
        }

        else if(guess<randnum){
            printf("\nHigher number please!");
        }

        else{
            printf("\nCongrats! your guess is correct\nNumber of attempts = %d",attempts);
        }
        
        attempts++;
    
    } while (guess != randnum);

    return 0;
}