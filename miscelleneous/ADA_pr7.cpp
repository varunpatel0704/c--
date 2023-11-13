#include <iostream>
// #include <limits>
#include <vector>
using namespace std;
int coin_change(const vector<int>& coins, const int target_sum) {
    vector<int> dp(target_sum + 1, 10e7);

    dp[0] = 0;

    for (int i = 1; i <= target_sum; ++i) {
        for (int c : coins) {
            if (c <= i) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    return dp[target_sum] != 10e7 ? dp[target_sum] : -1;
}

int main() {
    vector<int> coins = {10, 25, 5};
    int targetSum = 30;
    int min_coins = coin_change(coins, targetSum);
    cout << "Given set of coins: ";
    for(auto coin: coins)
        cout<<coin<<", ";
    cout << "\nRequired sum: " << targetSum << endl;
    cout << "Minimum number of coins needed: " << min_coins << endl;
    return 0;
}