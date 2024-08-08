#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int y = INT_MIN, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum = max(nums[i], nums[i] + sum);
            y = max(y, sum);
        }
        return y;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n; 
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i]; 
        }

        Solution sol;
        int result = sol.maxSubArray(nums);

        cout << result << endl; 
    }

    return 0;
}