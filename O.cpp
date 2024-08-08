#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
bool canObtainInitialArray(vector<int>& finalArray, int n) {
    if (finalArray[0] != 1) return false;
    
    vector<int> dp(5001, 0);
    dp[1] = 1;
    
    for (int i = 1; i < n; ++i) {
        if (!dp[finalArray[i]]) return false;
        
        for (int j = 5000; j >= finalArray[i]; --j) {
            dp[j] |= dp[j - finalArray[i]];
        }
    }
    
    return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int numCases;
    cin >> numCases;
    
    while (numCases--) {
        int n;
        cin >> n;
        
        vector<int> finalArray(n);
        for (int i = 0; i < n; ++i) {
            cin >> finalArray[i];
        }
        
        sort(finalArray.begin(), finalArray.end());
        
        if (canObtainInitialArray(finalArray, n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}