#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(int n, vector<int> &arr, int q) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int more = q - num;
        if (mpp.find(more) != mpp.end()) {
            return {mpp[more], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int>a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int>ans= twoSum(n,a,k);
        cout<< ans[0]<< " "<< ans[1];
    }}