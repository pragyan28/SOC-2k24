#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> portals(n); 
 
    for (int i = 1; i < n; ++i) {
        cin >> portals[i];
    }
 
    int current = 1;
    while (current < t) {
        current += portals[current];
    }
 
    if (current == t) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
 
    return 0;
}