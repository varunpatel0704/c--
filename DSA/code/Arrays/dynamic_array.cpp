#include <iostream>
using namespace std;

int main(){
    int n = 5;
    int * ptr = new int[n];
    // cout << "Taking input....." << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> ptr[n];
    // }
    
   
    ptr[0]=0;
    ptr[1]=1;
    ptr[2]=2;
    ptr[3]=3;
    ptr[4]=4;
    cout << "Printing array....." << endl;
    for (int j = 0; j < n; j++)
    {
        cout << ptr[j] << " ";
    }
    return 0;
}