#include <iostream>
#include <vector>
using namespace std;

class Node{

    public:

    int data;
    Node* left;
    Node* right;

    Node(){}

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

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
    

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    // your code here
    vector<int> heap;
    for(auto i: a)
        heap.push_back(i);
    for(auto i: b)
        heap.push_back(i);
    // now heapify (but this is 0 based heap)
    
    int size = heap.size();
    for(int i=(size)/2 - 1; i>=0; i--){
        heapify(heap, size, i);
    }

    return heap;
}

int main(){
    
    return 0;
}