#include <iostream>
#include <queue>

using namespace std;
struct Item{
    int value;
    int weight;
};
class compare{
    public:
    bool operator() (pair<Item, double>&a, pair<Item, double>&b){
        return a.second < b.second;
    }
};

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double maxProfit = 0;
        priority_queue<pair<Item, double>, vector<pair<Item, double>>, compare> maxHeap;
        
        // populate the maxHeap with pairs of items and their profit/weight ratios.
        for(int i=0; i<n; i++){
            double ratio = arr[i].value/arr[i].weight;
            maxHeap.push({arr[i], ratio});
        }
        
        int remainingCapacity = W;
        while(remainingCapacity >0){
            pair<Item, double> item = maxHeap.top();
            maxHeap.pop();
            int weight = item.first.weight;
            int value = item.first.value;
            if(remainingCapacity - weight >= 0){
                remainingCapacity -= weight;
                maxProfit += value;
            }
            
            else{
                int fractionalValue = remainingCapacity * item.second;
                remainingCapacity = 0;
                maxProfit += fractionalValue;
                break;
            }
        }
        
        return maxProfit;
    }
        
};

int main(){
    
    return 0;
}