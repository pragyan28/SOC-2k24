#include <bits/stdc++.h>
 
using namespace std;
 
class DSU {
public:
    vector<int> parent, size;
    
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
 
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
 
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};
 
int main() {
    int n, m;
    cin >> n >> m;
 
    DSU dsu(n + 1);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        if (k == 0) continue;
        vector<int> group(k);
        for (int j = 0; j < k; ++j) {
            cin >> group[j];
        }
        for (int j = 1; j < k; ++j) {
            dsu.unite(group[0], group[j]);
        }
    }
 
    vector<int> result(n + 1);
    for (int i = 1; i <= n; ++i) {
        result[i] = dsu.size[dsu.find(i)];
    }
 
    for (int i = 1; i <= n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
 
    return 0;
}