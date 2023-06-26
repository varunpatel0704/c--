#include <iostream>
#include <vector>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    // heap constructor, initialize 0th index with -1 because we won't store anything here.
    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int data)
    {
        // insert the element at the end of array
        arr[++size] = data;

        // now check whether it satisfies the max/min heap property.
        // place it at its correct postion of it violates heap property.

        int child_index = size; // to keep track of index of child element, initially the last index of the array.
        while (child_index > 1)
        {
            int parent_index = child_index / 2;
            if (arr[parent_index] < arr[child_index])
            { // we are checking for max heap property.
                swap(arr[parent_index], arr[child_index]);
                child_index = parent_index;
            }
            else
                return;
        }
    }

    void print()
    {
        for (int i = 1; i <=size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }    

    void pop()
    {
        // step 1 - replace root node with the last node.
        if (size != 0)
        {
            swap(arr[1], arr[size--]);
        }

        // step 2 - now readjust the nodes to maintain heap,
        // this will be done in a top to bottom order.
        int temp = 1;
        while ((2 * temp + 1) <= size)
        {
            int left = temp * 2 + 1, right = temp * 2, res;

            // get the index of maximum of left and right child
            if (arr[left] < arr[right])
                res = right;
            else
                res = left;

            if (arr[temp] < arr[res])
            {
                swap(arr[temp], arr[res]);
                temp = res;
            }
            else
                return;
        }
    }
};
void print(vector<int> arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


 void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    
    if(right < n && arr[largest] < arr[right])
        largest = right;
        
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

/* void heapify(vector<int> &arr, int index)
{   // check if current node is less than its children and whether it can be adjusted
    
    while(index*2+1 < arr.size()){
        int left = index * 2 + 1, right = index * 2, res;

        // get the index of maximum of left and right child
        if (arr[left] < arr[right])
            res = right;
        else
            res = left;

        if (arr[index] < arr[res])
        {
            swap(arr[index], arr[res]);
            index = res;
        }
        else
            return;
    }

    // recursive solution.

    // if(index*2+1 >= arr.size())
    //     return;

    // int left = index * 2, right = index*2 + 1, res;

    // if (arr.size() && arr[left] < arr[right])
    //     res = right;
    // else 
    //     res = left;

    // if (arr.size() && arr[index] < arr[res])
    // {
    //     swap(arr[index], arr[res]);
    //     index = res;
    //     heapify(arr, index);
    // }
    // else
    //     return;
}
*/
void buildMaxHeap(vector<int> &array){
    int index = array.size()/2;
    for (int i = index; i > 0; i--)
    {   
        heapify(array, array.size(), i);
    }
}

void heapSort(vector<int> &array){
    if(array.size() == 0 || array.size() == 1)
        return;

    
    int size = array.size()-1;
    while (size > 1) // atleast 2 elements are present in heap
    {
        // step 1 - swap first and last element
        swap(array[1], array[size]);
        
        // step 2 - decrement size and heapify remaining array.
        size--;
        int temp = 1;

        // this logic is same as deletion in heap (pop method).
        while ((2 * temp + 1) <= size)
        {
            int left = temp * 2 + 1, right = temp * 2, res;

            // get the index of maximum of left and right child
            if (array[left] < array[right])
                res = right;
            else
                res = left;

            if (array[temp] < array[res])
            {
                swap(array[temp], array[res]);
                temp = res;
            }
            else
                break;
        }
        

    }
    
}

int main()
{

    heap h1;
    h1.insert(40);
    h1.insert(30);
    h1.insert(15);
    h1.insert(10);
    h1.insert(20);
    h1.insert(7);
    h1.insert(8);
    h1.insert(13);

    // h1.print();

    // h1.pop();

    // h1.print();

  

    vector<int> array = {-1, 20, 7, 10, 33, 65, 5, 24};
    int index = 3; // starting with n/2 as the leafnodes are already heaps

    cout << "\narray before heapifying..." << endl;
    print(array);

    buildMaxHeap(array);

    cout << "\narray after heapifying..." << endl;
    print(array);

    cout << "\narray after applying heap sort..." << endl;
    heapSort(array);
    print(array);
    

    return 0;
}