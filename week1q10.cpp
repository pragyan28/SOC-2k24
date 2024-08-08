#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        map<int, int> mp;
        int cnt = 0;
        while (j < nums.size()) {
            mp[nums[j]]++;
            j++;
            cnt++;
            if (cnt >= k) {
                for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
                    ans.push_back(it->first);
                    break;
                }

                mp[nums[i]]--;
                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> result = sol.maxSlidingWindow(nums, k);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}