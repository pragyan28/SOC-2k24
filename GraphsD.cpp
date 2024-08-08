#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> parent, component_size;
 
int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}
 
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (component_size[a] < component_size[b]) swap(a, b);
        parent[b] = a;
        component_size[a] += component_size[b];
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    parent.resize(n + 1);
    component_size.resize(n + 1, 1);
    vector<unordered_set<int>> friends(n + 1);
 
    for (int i = 1; i <= n; ++i) parent[i] = i;
 
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        friends[a].insert(b);
        friends[b].insert(a);
        unite(a, b);
    }
 
    vector<vector<int>> components(n + 1);
    for (int i = 1; i <= n; ++i) {
        components[find(i)].push_back(i);
    }
 
    for (const auto& component : components) {
        if (component.size() < 2) continue;
        for (size_t i = 0; i < component.size(); ++i) {
            for (size_t j = i + 1; j < component.size(); ++j) {
                if (friends[component[i]].find(component[j]) == friends[component[i]].end()) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
 
    cout << "YES" << endl;
    return 0;
}