#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            int f;
            cin >> f;
            cout << 0 << endl;
            continue;
        }
 
        vector<long long int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
 
        vector<long long int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
 
        vector<long long int> prefixSum(n);
        prefixSum[0] = sortedArr[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + sortedArr[i];
        }
 
        vector<int> removalCount(n, 0);
        removalCount[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (prefixSum[i] >= sortedArr[i + 1]) {
                removalCount[i] = removalCount[i + 1];
            } else {
                removalCount[i] = i;
            }
        }
 
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(sortedArr.begin(), sortedArr.end(), arr[i]);
            int index = it - sortedArr.begin();
            if (i != n - 1) {
                cout << removalCount[index] << " ";
            } else {
                cout << removalCount[index] << endl;
            }
        }
    }
    return 0;
}