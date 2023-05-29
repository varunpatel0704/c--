#include <stdio.h>

void goodmorning();
void goodafternoon();
void goodnight();

int main(){
    goodmorning();
    

    return 0;
}
void goodmorning(){
    printf("Good morning Varun!\n");
    goodafternoon();
    
}
void goodnight(){
    printf("Good night Varun!\n");
}
void goodafternoon(){
    printf("Good afternoon Varun!\n");
    goodnight();
}


