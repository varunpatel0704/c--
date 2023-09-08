#include <iostream>
#include <time.h>
#include <vector>
#include <ctime>
#include <chrono>
using namespace std;

int linearSearch(vector<int> & arr, int n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(vector<int>& arr, int n, int key){
    int start=0;
    int end=n-1;

    int mid=start+(end-start)/2;

    while (start<=end)
    {
        if (arr[mid]==key)
        {
            return mid;
        }

        else if (key>arr[mid])
        {
            start=mid+1;
        }

        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }

    return -1;

}

int main(){
    // for (int i = 0; i < 10000; i++)
    // {
    //     // int random = (rand() );
    //     nums1[i] = random;
    // }

    vector<int> nums1(10e7);
    for(int j = 0; j < 10e7; j++)
        nums1[j] = j;
    // vector<int> nums2(nums1);

    auto start1 = std::chrono::system_clock::now();

    binarySearch(nums1, nums1.size(), 9999998);

    auto end1 = std::chrono::system_clock::now();


    long double start2 = clock();
    linearSearch(nums1, nums1.size(), 999998);
    long double end2 = clock();
    std::chrono::duration<double> elapsed_seconds = end1 - start1;

    // long double exe_time1 = ((long double)(end1 - start1))/CLOCKS_PER_SEC;
    cout<<"total time taken by binary search to find the key: "<<elapsed_seconds.count()<<endl;

    // long double exe_time2 = ((long double)(end2 - start2))/CLOCKS_PER_SEC;
    // cout<<"total time taken by linear search to find the key: "<<exe_time2<<endl;

    return 0;
}