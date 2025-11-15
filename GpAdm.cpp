#include <bits/stdc++.h>
using namespace std;

void BFS_matrix(vector<vector<int>> &mat, int start) {
    int n = mat.size();
    vector<int> vis(n, 0);
    queue<int> q;

    q.push(start);
    vis[start] = 1;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for(int v = 0; v < n; v++)
            if(mat[u][v] == 1 && !vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
    }
}

void DFS_matrix_util(vector<vector<int>> &mat, int u, vector<int> &vis) {
    vis[u] = 1;
    cout << u << " ";

    for(int v = 0; v < mat.size(); v++)
        if(mat[u][v] == 1 && !vis[v])
            DFS_matrix_util(mat, v, vis);
}

void DFS_matrix(vector<vector<int>> &mat, int start) {
    vector<int> vis(mat.size(), 0);
    DFS_matrix_util(mat, start, vis);
}

int main() {
    vector<vector<int>> mat = {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,1},
        {0,1,1,0}
    };

    cout << "BFS (Adj Matrix): ";
    BFS_matrix(mat, 0);

    cout << "\nDFS (Adj Matrix): ";
    DFS_matrix(mat, 0);
}
