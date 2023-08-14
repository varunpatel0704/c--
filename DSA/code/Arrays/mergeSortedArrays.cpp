#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeArrays(vector<int> &arr1,  vector<int> &arr2){
    int i=0, j=0;
    vector<int> vec3;    
    while (i<arr1.size() and j<arr2.size())
    {
        if(arr1[i]==arr2[j]){
            vec3.push_back(arr1[i]);
            vec3.push_back(arr2[j]);
            j++;
            i++;
        }
        else if (arr1[i]>arr2[j])
        {
            vec3.push_back(arr2[j]);
            j++;
        }
        else{
            vec3.push_back(arr1[i]);
            i++;
        }
        
    }
    while (i<arr1.size())
    {
        vec3.push_back(arr1[i]);
        i++;
    }
    while (j<arr2.size())
    {
        vec3.push_back(arr2[j]);
        j++;
    }
    


    return vec3;
}

int main(){
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(3);
    arr1.push_back(5);
    arr1.push_back(7);
    arr1.push_back(9);

    vector<int> arr2;
    arr2.push_back(2);
    arr2.push_back(4);
    arr2.push_back(6);

    vector<int> arr3=mergeArrays(arr1,arr2);

    cout<<"\nPrinting merged array "<< endl;
    for (int i=0; i<arr3.size(); i++)
    {
        cout<<arr3[i]<<" ";
    }
    
    return 0;
}