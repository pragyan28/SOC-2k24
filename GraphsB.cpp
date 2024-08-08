#include <bits/stdc++.h>
 
using namespace std;
 
 
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component, vector<int>& costs) {
    visited[node] = true;
    component.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, component, costs);
        }
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    
    vector<bool> visited(n, false);
    long long total_cost = 0;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, adj, visited, component, costs);
            
            int min_cost = INT_MAX;
            for (int node : component) {
                if (costs[node] < min_cost) {
                    min_cost = costs[node];
                }
            }
            
            total_cost += min_cost;
        }
    }
    
    cout << total_cost << endl;
    
return 0;
}