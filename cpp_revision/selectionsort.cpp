#include <iostream>
using namespace std;

void selectionsort(int *arr, int n){
    for (int i = 0; i < n-1; i++){
        int minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[minIndex])
            {
                minIndex = j;
            }
            
        }
        swap(arr[i], arr[minIndex]);
        
    }
}

int main(){
    int arr[6] = {64,2,3,2,87,-1};
    int n = 6;
    selectionsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}