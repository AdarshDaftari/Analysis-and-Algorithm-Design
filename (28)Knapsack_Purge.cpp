#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int profit;
};


vector<Item> merge(vector<Item>& left, vector<Item>& right) {
    vector<Item> merged;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i].profit > right[j].profit) {
            merged.push_back(left[i]);
            i++;
        } else {
            merged.push_back(right[j]);
            j++;
        }
    }
    while (i < left.size()) {
        merged.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        merged.push_back(right[j]);
        j++;
    }
    return merged;
}


int knapsack(vector<Item>& items, int capacity) {
    vector<int> dp(capacity + 1, 0);
    for (Item item : items) {
        for (int w = capacity; w >= item.weight; w--) {
            dp[w] = max(dp[w], dp[w - item.weight] + item.profit);
        }
    }
    return dp[capacity];
}

int main() {
    int n; 
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;
    for (int i = 0; i < n; i++) {
        int weight, profit;
        cout << "Enter weight and profit for item " << i + 1 << ": ";
        cin >> weight >> profit;
        items.push_back({weight, profit});
    }

    int capacity;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;

   
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.profit > b.profit;
    });

    
    vector<Item> lowestWeightSet = items;
    vector<Item> mostProfitSet = items;

    
    int totalWeight = 0;
    for (const Item& item : items) {
        totalWeight += item.weight;
    }
    int averageWeight = totalWeight / n;
    lowestWeightSet.erase(remove_if(lowestWeightSet.begin(), lowestWeightSet.end(),
                                     [averageWeight](const Item& item) {
                                         return item.weight > averageWeight;
                                     }),
                           lowestWeightSet.end());

    
    int totalProfit = 0;
    for (const Item& item : items) {
        totalProfit += item.profit;
    }
    int averageProfit = totalProfit / n;
    mostProfitSet.erase(remove_if(mostProfitSet.begin(), mostProfitSet.end(),
                                   [averageProfit](const Item& item) {
                                       return item.profit < averageProfit;
                                   }),
                         mostProfitSet.end());

    // Finding maximum profit using knapsack for each set
    int maxProfitLowestWeight = knapsack(lowestWeightSet, capacity);
    int maxProfitMostProfit = knapsack(mostProfitSet, capacity);

    cout << "Maximum profit for items with lowest weight: " << maxProfitLowestWeight << endl;
    cout << "Corresponding weight: " << capacity << endl; // Knapsack's capacity
    cout << "Maximum profit for items with most profit: " << maxProfitMostProfit << endl;
    cout << "Corresponding weight: " << capacity << endl; // Knapsack's capacity

    return 0;
}
