#include <vector>
#include <time.h>
#include <iostream>
using namespace std;

void printArr(vector<int> &arr, int len){
    
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

void bubbleSort(vector<int> &arr, int len){
    bool swapped=false;
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
            
        }

        if (swapped==false)//<-- this is to optimise the code. break when the array is already sorted.
        {
            // cout<<"\nalready sorted"<<endl;
            break;
        }
        
    }
}

void selectionSort(vector<int> &arr, int len){
    for (int i = 0; i < len-1; i++)
    {
        int minIndex=i;
        for (int j = i+1; j < len; j++)
        {
            if (arr[minIndex]>arr[j])
            {
                minIndex=j;
            }
            
        }
        swap( arr[i],arr[minIndex]);
        
    }
    
}

void insertionSort(vector<int> &arr, int len){

    for (int i = 1; i < len; i++){
        int temp = arr[i];
        int j = i-1;
        while (arr[j] > temp and j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

// merge sort
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

// quick sort
int partition(vector<int> &arr, int start, int end){

    int count = 0; // count of elements smaller then pivot(first) element.

    for (int i = start; i <= end; i++)
    {
        if(arr[i] < arr[start]) // if ith elements is smaller than pivot element then count++.
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]); // placing pivot on it's correct position.

    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] < arr[pivotIndex]){
            i++;
        }
       
        while(arr[j] > arr[pivotIndex]){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);  // all smaller elements on left side.
    }                                  // all greater elements on right side.
    
    return pivotIndex;
}

void quickSort(vector<int> &arr, int start, int end){
    if (start < end)
    {
        int pivot = partition(arr, start, end);

        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }

    else
        return;
    
}

int main(){
 
    vector<int> nums1(20000);
    for (int i = 0; i < 20000; i++)
    {
        int random = (rand() % 100);
        nums1[i] = random;
    }
    vector<int> nums2(nums1);

    vector<int> nums3(nums1);

    vector<int> nums4(nums1);
    vector<int> nums5(nums1);
    // printArr(nums, nums.size());
    
    long double start1 = clock();
    mergeSort(nums1, 0, nums1.size()-1);
    long double end1 = clock();

    long double start2 = clock();
    quickSort(nums2, 0, nums2.size()-1);
    long double end2 = clock();

    long double start3 = clock();
    bubbleSort(nums3, nums3.size());
    long double end3 = clock();

    long double start4 = clock();
    selectionSort(nums4, nums4.size());
    long double end4 = clock();

    long double start5 = clock();
    insertionSort(nums5, nums5.size());
    long double end5 = clock();
    
    long double exe_time1 = ((long double)(end1 - start1))/CLOCKS_PER_SEC;
    long double exe_time2 = ((long double)(end2 - start2))/CLOCKS_PER_SEC;
    long double exe_time3 = ((long double)(end3 - start3))/CLOCKS_PER_SEC;
    long double exe_time4 = ((long double)(end4 - start4))/CLOCKS_PER_SEC;
    long double exe_time5 = ((long double)(end5 - start5))/CLOCKS_PER_SEC;
    cout<<endl<<endl<<"sorted array"<<endl;

    cout<<"total time taken by mergeSort to sort the array: "<<exe_time1<<endl;
    cout<<"total time taken by quickSort to sort the array: "<<exe_time2<<endl;
    cout<<"total time taken by bubbleSort to sort the array: "<<exe_time3<<endl;
    cout<<"total time taken by selectionSort to sort the array: "<<exe_time4<<endl;
    cout<<"total time taken by insertionSort to sort the array: "<<exe_time5<<endl;
    
    return 0;
}