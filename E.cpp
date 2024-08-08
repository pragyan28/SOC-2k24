#include <iostream>
#include <map>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        long long int n, k, p, q;
        cin >> n >> k;
 
        map<int, pair<long long int, long long int>> m;
        long long int v[n];
        for (long long int i = 0; i < n; i++) {
            cin >> v[i];
            if (m[v[i]].first != 0) {
                m[v[i]].second = i + 1;
            } else {
                m[v[i]].first = i + 1;
                m[v[i]].second = i + 1;
            }
        }
 
        for (long long int i = 0; i < k; i++) {
            cin >> p >> q;
            long long int s = m[q].first;
            long long int l = m[p].second;
            bool f = false;
            if (s == 0 || l == 0) {
                f = false;
            } else {
                f = m[p].first < m[q].second;
            }
            if (f) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
 
    return 0;
}