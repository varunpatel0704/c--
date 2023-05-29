#include <iostream>
using namespace std;


void bubblesort(int *arr, int n){
    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
        
        for (int j = 0 ; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            
        }
        if(swapped == false)
            break;
        
    }
    

}

int main(){
    int arr[6] = {64,2,3,2,87,-1};
    int n = 6;
    bubblesort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}