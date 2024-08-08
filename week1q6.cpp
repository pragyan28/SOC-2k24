#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n ;
        vector<int>a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int smallest= INT_MAX;
        for(int i=0; i<n; i++){
            if(a[i]< smallest) smallest= a[i];
        }
        cout<< smallest;
        }
        
    }