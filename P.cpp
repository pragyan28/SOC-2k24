#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> balls(n);
        for (int i = 0; i < n; ++i) {
            cin >> balls[i];
        }
 
        sort(balls.begin(), balls.end());
        
        if (balls[0] != 1) {
            cout << "NO" << endl;
            continue;
        }
 
        long long csum = balls[0];
        bool flag = true;
 
        for (int i = 1; i < n; ++i) {
            if (balls[i] <= csum) {
                csum += balls[i];
            } else {
                flag = false;
                break;
            }
        }
 
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}