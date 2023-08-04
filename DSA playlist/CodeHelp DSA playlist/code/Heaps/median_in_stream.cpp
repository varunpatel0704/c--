#include <iostream>
#include <queue>
using namespace std;



int signum(int a, int b){
	if(a == b)
		return 0;
	
	else if(a > b)
		return 1;

	else 
		return -1;
}

void getMedian(priority_queue<int, vector<int>, greater<int>> &minHeap,
			 priority_queue<int> &maxHeap, int &element, int &median){

	switch ( signum(maxHeap.size(), minHeap.size()) ){
		
		// both heaps have equal sizes
		case 0:
			if(element > median){
				minHeap.push(element);
				median = minHeap.top();
			}
			else{
				maxHeap.push(element);
				median = maxHeap.top();
			}

			break;
		
		// minHeap.size > maxHeap.size
		case 1:
			if(element > median){
				minHeap.push(element);
				median = (minHeap.top() + maxHeap.top())/2;
			}
			
			else{
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(element);
				median = (minHeap.top() + maxHeap.top())/2;
			}
			
			break;
		
		// minHeap.size < maxheap.size
		case -1:
			if(element > median){
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(element);
				median = (minHeap.top() + maxHeap.top())/2;
			}
			else{
				maxHeap.push(element);
				median = (minHeap.top() + maxHeap.top())/2;
			}
			
			break;
	}
}

vector<int> findMedian(vector<int> &arr, int n){
	
	// create minHeap and maxHeap
	priority_queue<int, vector<int>, greater<int>> minHeap;
	priority_queue<int> maxHeap;

	int median = 0;
	vector<int> ans;
	
	// start processing the stream.
	for(int i=0; i<n; i++){
		getMedian(minHeap, maxHeap, arr[i], median);
		ans.push_back(median);
	}

	return ans;
}


int main(){
    
    return 0;
}