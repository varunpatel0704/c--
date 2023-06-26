#include <iostream>
#include <queue>
using namespace std;

class Container{
    public:
        int data;
        int row;
        int col;
        
        Container(int val, int i, int j){
            data = val;
            row = i;
            col = j;
        }
};

class compare{
    public:
        bool operator() (Container* a, Container* b){
            /* the order the heap will be decided based on comparator
               if the comparator returns true then the node is at its correct 
               position and no swaps will be made otherwise the node will
               be placed at its correct position(insertion operation)
               
               in case of max heap the smaller values will remain at lower values
               and in case of min heap the larger values will remain at lower values.
               if a > b then in case of min heap, the comparator should return true since
               larger values reside at the bottom 
               Similarly in case of max heap, the comparator should return false for a > b
               since smaller values should be at the bottom.*/
           
            if(a->data > b->data) 
                return true;
            else
                return false;
        }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    priority_queue<Container*, vector<Container*>, compare> minHeap;
    
    // push the first element of all the arrays into the heap.
    for(int i=0; i<arr.size(); i++){
        Container* temp = new Container(arr[i][0], i, 0); // we need to use 'Container*', a pointer because we are using dynamic alloc
        minHeap.push(temp);
    }
    
    vector<int> ans;
    
    while(!minHeap.empty()){
        // pop the heap top and push it into output array.
        Container* temp = minHeap.top();
        minHeap.pop();
        
        ans.push_back(temp->data);
        
        // now check if there are anymore elements left in the row
        // or array from which we just popped.
        int row = temp->row;
        int col = temp->col;
        
        if(col+1 < K){
            // create a container for this element and push it into the heap
            Container* nextVal = new Container(arr[row][col+1], row, col+1);
            minHeap.push(nextVal);
        }
    }
    
    return ans;
    
}

int main(){
    
    return 0;
}