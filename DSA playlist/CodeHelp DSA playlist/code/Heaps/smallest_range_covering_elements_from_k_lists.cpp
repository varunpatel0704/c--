#include <iostream>
#include <queue>
using namespace std;

class Container{
    public:
        int data;
        int row;
        int col;

        Container(int data, int row, int col){
            this->data = data;
            this->row = row ;
            this->col = col;
        }
};

class compare{
    public:
        bool operator() (Container* a, Container* b){
            return (a->data > b->data);
        }
};

vector<int> smallestRange(vector<vector<int>>& nums) {
    // create a minHeap and insert first element of all K arrays.
    priority_queue<Container*, vector<Container*>, compare> minHeap;
    int maxVal = INT32_MIN;
    
    for(int i=0; i<nums.size(); i++){
        Container* temp = new Container(nums[i][0], i, 0);
        maxVal = max(maxVal, temp->data);
        minHeap.push(temp);
    }

    // now keep processing till heap is not empty or 
    // one of the arrays is not exhausted.
    int higher = maxVal, lower = minHeap.top()->data;

    while(!minHeap.empty()){
        // update min val.
        Container* minVal = minHeap.top();
        minHeap.pop();

        // now update the range if a smaller interval is found
        if(maxVal-minVal->data < higher-lower){
            higher = maxVal;
            lower = minVal->data;
        }
        
        // now check if there are anymore elements in the row to which minVal belongs
        int row = minVal->row, col = minVal->col;
        if(col+1 < nums[row].size()){
            Container* temp = new Container(nums[row][col+1], row, col+1);
            minHeap.push(temp);
            maxVal = max(maxVal, temp->data);
        }

        // else the array has been exhausted hence the minVal can't be updated any further therfore break.
        else{
            break;
        }
    }

    vector<int> ans;
    ans.push_back(lower);
    ans.push_back(higher);

    return ans;
}

int main(){
    
    return 0;
}