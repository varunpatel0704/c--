#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> &arr, int len){
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(vector <int>& nums, int start, int mid, int end){
    
    int len1 = mid - start + 1;
    int len2 = end - mid;
    
    vector <int> left(len1);
    vector <int> right(len2);
    
    int mainIndex = start;
    for(int i = 0; i < len1; i++){

        left[i] = nums[mainIndex++];
    
    }
    
    for(int i = 0; i < len2; i++){

        right[i] = nums[mainIndex++];
    
    }
    
    mainIndex = start;
    int i = 0, j = 0;
    
    while(i < len1 && j < len2){
        if(left[i] < right[j])
            nums[mainIndex++] = left[i++];
        
        else
            nums[mainIndex++] = right[j++];
    }
    
    while(i < len1){
        nums[mainIndex++] = left[i++];
    }
    
    while(j < len2){
        nums[mainIndex++] = right[j++];
    }
}

void mergeSort(vector<int>& nums, int start, int end){

    if(start < end){
        int mid = start + (end - start)/2;
        
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        
        merge(nums, start, mid, end);
    }
    
    else
        return;   
}

vector<int> sortArray(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    
    mergeSort(nums, start, end);
    
    return nums;
}

int main(){
    
    vector <int> arr= {34,6,0,2,5,1,-6,76,-76,41,98};
    
    printArr(arr, 11);
    
    mergeSort(arr, 0, 10);

    printArr(arr, 11);


    return 0;
}