#include <iostream>
using namespace std;
// Call by value function
void swap(int a, int b){
    int temp=a;         
    a=b;                
    b=temp;             
}
void swapReferenceVar(int &x, int &y){
    int temp=x;         
    x=y;                
    y=temp;             
}

// Call by reference using pointers
void swapPointer(int* a, int* b){//temp a b
    int temp=*a;                 //4    4 5
    *a=*b;                       //4    5 5
    *b=temp;                     //4    5 4
}


int main(){
    int a=4 , b=5;
    cout<<"Without using swap function the value of a is "<<a<<" and the value of b is "<<b<<endl;
    swap(a,b);
    //This will not swap the value of a and b 
    cout<<"Using swap function the value of a is "<<a<<" and the value of b is "<<b<<endl;
    // swapPointer(&a,&b);
    // cout<<"Using the swapPointer function value of a is "<<a<<" and the value of b is "<<b<<endl;
    swapReferenceVar(a,b);
    cout<<"Using the swapReferenceVar function value of a is "<<a<<" and the value of b is "<<b<<endl;

    return 0;
}