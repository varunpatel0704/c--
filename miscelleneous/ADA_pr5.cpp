#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n, vector<vector<int>> &K) {
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][W];
}

int main() {
    vector<int> val = {1, 2, 5, 6};
    vector<int> wt = {2, 3, 4, 5};
    int W = 8;
    int n = val.size();

    // 2D matrix to store results of dp calculations.
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));
    vector<pair<int, int>> items;

    int maxProfit = knapsack(W, wt, val, n, K);
    cout << "0/1 Knapsack problem \n" << endl;
    cout << "The results stored in the table are: " <<endl;
    for(int i=0; i<n+1; i++){
        for(int j=0; j<W+1; j++){
            cout<<setw(3)<<K[i][j]<<", ";
        }cout<<endl;
    }

    int i=n-1, remainingProfit = K[n][W];
    while(i>=0){
        bool found = 0;
        for(int j=0; j<W+1; j++){
            if(K[i][j] == remainingProfit){
                found = true;
                break;
            }
        }
        if(!found){
            items.push_back({val[i], wt[i]});
            remainingProfit -= val[i];
        }
        i--;
    }
    cout << "\nSet of selected items(val, wt): " <<"";
    for(auto pair: items){
        printf("(%d, %d), ", pair.first, pair.second);
    }
    cout << "\nMaximum profit: " << maxProfit << endl;
    return 0;
}