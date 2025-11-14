#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 
struct Job { 
int id;        
int dead;     
// Job ID 
 // Deadline 
int profit;    // Profit 
}; 
// Sort jobs by profit in descending order 
bool cmp(Job a, Job b) { 
return a.profit > b.profit; 
} 
int main() { 
int n; 
cout << "Enter number of jobs: "; 
cin >> n; 
vector<Job> jobs(n); 
cout << "Enter job id, deadline, profit:\n"; 
for (int i = 0; i < n; i++) { 
cin >> jobs[i].id >> jobs[i].dead >> jobs[i].profit; 
} 
// Step 1: Sort jobs by profit (descending) 
sort(jobs.begin(), jobs.end(), cmp); 
 
    // Step 2: Find maximum deadline 
    int maxDeadline = 0; 
    for (auto &j : jobs) 
        maxDeadline = max(maxDeadline, j.dead); 
 
    // Step 3: Create a timeslot array 
    vector<int> slot(maxDeadline + 1, -1); 
 
    int totalProfit = 0; 
    int jobsDone = 0; 
 
    // Step 4: Greedily assign jobs 
    for (int i = 0; i < n; i++) { 
        // Try to schedule job at its deadline or earlier 
        for (int t = jobs[i].dead; t > 0; t--) { 
            if (slot[t] == -1) { 
                slot[t] = jobs[i].id;     // Job is assigned 
                totalProfit += jobs[i].profit; 
                jobsDone++; 
                break; 
            } 
        } 
    } 
 
    // Output results 
    cout << "\nNumber of jobs done: " << jobsDone << endl; 
    cout << "Total profit: " << totalProfit << endl; 
 
    cout << "Jobs sequence: "; 
    for (int i = 1; i <= maxDeadline; i++) { 
if (slot[i] != -1) 
cout << slot[i] << " "; 
} 
}