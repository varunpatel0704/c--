#include <iostream>
using namespace std;

void update1(int i){

    i++;

}
void update2(int &i){

    i++;

}

int main(){
   
    // int i = 189;
    // int &j = i;
    // cout << i++ << endl;
    // cout << j<< endl;

    // update1(i); // call by value
    // cout << i<< endl;
    
    // update2(j); // call by reference.
    // cout << j<< endl;

    int * ptr = new int;
    *ptr = 100;
    cout <<" before delete: "<< ptr << endl;
    cout << *ptr << endl;

    int *arr = new int [50];
    arr[0] = 69;
    cout << *arr << endl;
    cout << arr << endl;
    cout << arr+1 << endl;

    delete ptr;
    
    cout <<" after delete: "<< ptr << endl;
    cout << *ptr << endl;

    delete []arr;
    return 0;
}