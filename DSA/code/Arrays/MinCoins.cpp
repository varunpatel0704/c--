#include <iostream>
#include <vector>
using namespace std;

vector<int> minPartition(int N)
{
    vector<int> coins = {1,2,5,10,20,50,100,200,500,2000};
    vector<int> ans;
    int sum = 0, i = 9;
    int count =0 ;
    while(sum<N and i>=0){
        if(sum+coins[i] <= N){
            sum+=coins[i];
            ans.push_back(coins[i]);
        }
        else{
            i--;
        }        
    }
    return ans;
}

int main(){

return 0;
}