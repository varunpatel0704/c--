#include <iostream>
using namespace std;

void insertionsort(int * arr, int n){
    for (int i = 1; i < n; i++)
    {   
        int temp = arr[i];
        int j = i - 1;
        while (temp < arr[j]  and j >= 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    
}

int main(){
    int arr[6] = {64,2,3,2,87,-1};
    int n = 6;
    insertionsort(arr, 6);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}
