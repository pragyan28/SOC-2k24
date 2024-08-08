#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> sum(n + 1, 0);
    int minLength = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + nums[i];
    }

    for (int i = 0; i < n + 1; ++i) {
        for (int j = i + 1; j < n + 1; ++j) {
            if (sum[j] - sum[i] >= k) {
                minLength = min(minLength, j - i);
                break;
            }
        }
    }

    return minLength == numeric_limits<int>::max() ? -1 : minLength;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << shortestSubarray(nums, k) << endl;
    }

    return 0;
}