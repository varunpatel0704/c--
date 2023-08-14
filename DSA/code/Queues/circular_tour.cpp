#include <iostream>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
{
    //Your code here
    int front = 0;
    int balance = 0, deficit = 0;
    for(int i = 0; i < n; i++){
        // calculate balance at the start
        balance = balance + p[i].petrol - p[i].distance;
        
        if(balance < 0){ // out of fuel at this point.
            deficit+= balance; // record the deficit till now.
            balance = 0; // reset balance to 0 for new journey.
            front = i+1; // re-try from next petrol bunk.
        }
    }
    if(deficit + balance >= 0)
        return front;
    else
        return -1;
    
}

int main(){
    
    return 0;
}