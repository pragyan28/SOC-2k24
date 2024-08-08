#include<bits/stdc++.h>
using namespace std;
 
int main() {
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            cin >> a[i];
        }
 
        sort(a.begin(), a.end());
 
        vector<pair<int, int>> points;
        for (int i = 0; i < n; ++i) {
            points.push_back({a[i], a[2*n - i- 1]});
        }
         int td = 0;
        for (int i = 1; i < n; ++i) {
            td += abs(points[i].first - points[i-1].first) + abs(points[i].second - points[i-1].second);
        }
        cout << td << "\n";
 
        for (auto &point : points) {
            cout << point.first << " " << point.second << "\n";
        }
       
        
    }
 
    return 0;
}