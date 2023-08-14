#include <iostream>
using namespace std;

void print(int *p){

    cout << p << endl;
    cout << *p << endl;
}

void update(int * p){
    p = p + 1; // &(arr+1) = &arr[1]
    cout << p << endl;
    *p = *p + 1;// arr[1] + 1;
    cout << *p << endl; // arr[1]; 2+1 = 3.
}

int getSum(int *arr, int n){
    cout << "size of arr is : " << sizeof(arr) << endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {   
        sum += i[arr]; 
    }
    return sum;
}    
    

int main(){
    
    int arr[5] = {1,2,3,4,5};
    int *p = arr;
    
    cout<<p << endl;
    
    print(p);
    
    update(p);
    
    cout<<getSum(arr+2, 3)<<" is the sum"; // finds sum for elements after arr[2].
    return 0;
}