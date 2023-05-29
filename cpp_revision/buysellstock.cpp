#include <iostream>
#include <vector>
using namespace std;

 int maxProfit(vector<int>& prices) {
    int buyprice = prices[0], max_profit = 0;
    for(int i = 1; i < prices.size(); i++){
        int sellprice = prices[i];
        cout<<"buyprice = " <<buyprice<<" sellprice = "<<sellprice<<" max profit = "<<max_profit<<endl;
        if(sellprice < buyprice)
            buyprice = prices[i];
        else{
            int profit = sellprice - buyprice;
            max_profit = max(max_profit, profit);
        }
    }
    return max_profit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    maxProfit(prices);
    return 0;
}