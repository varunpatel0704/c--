#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    
    int ** arr = new int * [n]; // creates an array of pointers in heap.

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int [n]; // creates n(read as n rows) arrays of size n(read as n cols).
    }
    
    cout << "Takig input....." << endl;
    
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++) // taking input as in case of normal
        {                           // 2D matrix.
            cin >> arr[j][k];
        }
        
    }
    arr[2][2] = 2;
    cout << "Takig output....." << endl;

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            cout<< arr[j][k] << " "; // Printing the matrix.
        }
        cout<<endl;
        
    }
    
    for (int i = 0; i < n; i++)
    {
        delete []arr[i]; // deallocating the heap memory 
                         // row wise.
    }
    
    delete []arr;// deleting the array of pointers.
    
    //cout << arr[1][2];
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            cout<< arr[j][k] << " "; // Printing the matrix.
        }
        cout<<endl;
        
    }
    return 0;
}