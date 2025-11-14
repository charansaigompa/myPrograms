#include <iostream> 
#include <vector> 
using namespace std; 
 
int bestValue = 0;  // store the maximum profit found 
 
void backtrack(int i, int currWeight, int currValue,  
               vector<int>& wt, vector<int>& val, int W, int n) { 
     
    // If weight exceeds capacity → invalid path 
    if (currWeight > W)  
        return; 
 
    // Update the best value 
    bestValue = max(bestValue, currValue); 
 
    // If all items checked → return 
    if (i == n) 
        return; 
 
    // ------------------------- 
    // Option 1: Include item i 
    // ------------------------- 
    backtrack(i + 1, 
              currWeight + wt[i], 
              currValue + val[i], 
              wt, val, W, n); 
 
    // ------------------------- 
    // Option 2: Exclude item i 
// ------------------------- 
backtrack(i + 1, currWeight, currValue, wt, val, W, n); 
} 
int main() { 
int n, W; 
cout << "Enter number of items: "; 
cin >> n; 
vector<int> wt(n), val(n); 
cout << "Enter item weights:\n"; 
for(int i = 0; i < n; i++) cin >> wt[i]; 
cout << "Enter item values:\n"; 
for(int i = 0; i < n; i++) cin >> val[i]; 
cout << "Enter max capacity: "; 
cin >> W; 
backtrack(0, 0, 0, wt, val, W, n); 
cout << "\nMaximum value = " << bestValue; 
}