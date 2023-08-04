#include <iostream>
#include <queue>
using namespace std;

// marked for review
vector<int> merge2Arrays(vector<int>arr1, vector<int> arr2)
{
    vector<int> ans;
    
    int n1=arr1.size();
    int n2=arr2.size();
    
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            ans.push_back(arr1[i++]);
        }else{
            ans.push_back(arr2[j++]);
        }
    }
    
    while(i<n1){
        ans.push_back(arr1[i++]);
    }
    
    while(j<n2){
        ans.push_back(arr2[j++]);
    }
    
    return ans;
}

vector<int> solve(vector<vector<int>> arr,int start, int end,int K)
{
    //if size of array become one
    if(start== end){
        return arr[start];
    }
    
    // if size of array is two
    if(end-start == 1){
        return merge2Arrays(arr[start],arr[end]);
    }
    
    // if size of array is greater than 2
    if(end-start > 1){
        vector<int> left=solve(arr,start,(start+end)/2,K);
        vector<int> right=solve(arr,((start+end)/2)+1,end,K);
        
        return merge2Arrays(left,right);   
    }
    
}

//Function to merge k sorted arrays.
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // int size=arr.size();    
    return solve(arr,0,K-1,K);
}




// my solution.
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