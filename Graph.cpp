#include <bits/stdc++.h>
using namespace std;

void BFS_list(vector<vector<int>> &g, int start) {
    int n = g.size();
    vector<int> vis(n, 0);
    queue<int> q;

    q.push(start);
    vis[start] = 1;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for(int v : g[u])
            if(!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
    }
}

void DFS_list_util(vector<vector<int>> &g, int u, vector<int> &vis) {
    vis[u] = 1;
    cout << u << " ";

    for(int v : g[u])
        if(!vis[v])
            DFS_list_util(g, v, vis);
}

void DFS_list(vector<vector<int>> &g, int start) {
    vector<int> vis(g.size(), 0);
    DFS_list_util(g, start, vis);
}

int main() {
    vector<vector<int>> g = {
        {1,2},      // 0
        {0,3},      // 1
        {0,3},      // 2
        {1,2}       // 3
    };

    cout << "BFS (Adj List): ";
    BFS_list(g, 0);

    cout << "\nDFS (Adj List): ";
    DFS_list(g, 0);
}
