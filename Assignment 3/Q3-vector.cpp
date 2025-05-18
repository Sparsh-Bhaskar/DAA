#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum profit
int knapSack(int W, int wt[], int val[], int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w-wt[i-1]]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // Finding the items included in the knapsack
    int res = dp[n][W];
    int w = W;
    cout << "Items selected: ";
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i-1][w])
            continue;
        else {
            cout << "Item " << i << " ";
            res = res - val[i-1];
            w = w - wt[i-1];
        }
    }
    cout << endl;

    return dp[n][W];
}

int main() {
    int profit[] = {5, 3, 8, 6};
    int weight[] = {2, 3, 4, 5};
    int W = 7;
    int N = sizeof(profit) / sizeof(profit[0]);

    cout << "Maximum profit: " << knapSack(W, weight, profit, N) << endl;

    return 0;
}