#include <iostream> 
#include <vector> 
using namespace std; 
 
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) { 
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); 
 
    // Build DP table 
    for (int i = 1; i <= n; i++) { 
        for (int w = 1; w <= W; w++) { 
 
            // If current item's weight is less than or equal to current capacity 
            if (wt[i - 1] <= w) { 
                dp[i][w] = max( 
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],  // include item 
                    dp[i - 1][w]                             // exclude item 
                ); 
            }  
            else { 
                dp[i][w] = dp[i - 1][w];   // cannot include item 
            } 
        } 
    } 
 
    return dp[n][W]; 
} 
 
int main() { 
    int n, W; 
 
cout << "Enter number of items: "; 
cin >> n; 
vector<int> wt(n), val(n); 
cout << "Enter weights of items:\n"; 
for (int i = 0; i < n; i++) cin >> wt[i]; 
cout << "Enter values of items:\n"; 
for (int i = 0; i < n; i++) cin >> val[i]; 
cout << "Enter max capacity of knapsack: "; 
cin >> W; 
cout << "Maximum value in knapsack = " << knapsack(W, wt, val, n); 
}