#include<bits/stdc++.h>
using namespace std;
 
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
 
        unordered_map<long long int, long long int> m;
        for (int j = 0; j < n; j++) {
            long double t = log(a[j]) - a[j] * log(2);
            long long int r = round(t*100000);
            m[r]++;
        }
 
        long long int c = 0;
        for (const auto &p : m) {
            if (p.second > 1) {
                c += (p.second * (p.second - 1)) / 2;
            }
        }
        cout << c << endl;
    }
    return 0;
}