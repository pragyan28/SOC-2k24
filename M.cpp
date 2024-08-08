#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int arr[n];
        for (auto &num : arr) {
            cin >> num;
        }
 
        long long int total_sum = 0, min_prefix_sum = 0;
        for (int i = 0; i < n; i++) {
            total_sum += arr[i];
            min_prefix_sum = min(min_prefix_sum, total_sum);
        }
        
        cout << total_sum - 2 * min_prefix_sum << "\n";
    }
 
    return 0;
}