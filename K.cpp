#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> health(n), position(n);
        for (auto &h : health) cin >> h;
        for (auto &p : position) cin >> p;
        
        vector<long long> health_sum(n + 1);
        for (int i = 0; i < n; ++i) {
            health_sum[abs(position[i])] += health[i];
        }
        
        bool possible = true;
        long long left_bullets = 0;
        for (int i = 1; i <= n; ++i) {
            left_bullets += k - health_sum[i];
            possible &= (left_bullets >= 0);
        }
        
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}