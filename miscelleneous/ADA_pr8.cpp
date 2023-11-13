#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Item {
    int value;
    int weight;
    double ratio;

    Item(int v, int w) : value(v), weight(w), ratio((double)v / w) {}
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int knapsack_greedy(int W, vector<Item>& items) {
    int n = items.size();
    int max_val = 0;

    sort(items.begin(), items.end(), compare);

    for (int i = 0; i < n; ++i) {
        if (W >= items[i].weight) {
            max_val += items[i].value;
            W -= items[i].weight;
        } 
        else {
            max_val += W * items[i].ratio;
            break;
        }
    }

    return max_val;
}

int main() {
    vector<Item> items = {
        {10, 5},
        {40, 4},
        {30, 6},
        {50, 3},
    };
    int W = 10;
    int max_val = knapsack_greedy(W, items);
    cout << "Given set of profit and weights: ";
    for(auto item: items)
        cout << "(" << item.value << "," << item.weight << "), ";
    cout << "\nCapacity of knapsack: " << W << endl;
    cout << "Maximum Profit: " << max_val << endl;
    return 0;
}
