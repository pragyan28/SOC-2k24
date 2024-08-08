#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    long long D;
    cin >> N >> D;
 
    vector<long long> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    sort(P.begin(), P.end());
 
    int wins = 0;
    int left = 0, right = N - 1;
    while (left <= right) {
        long long q = P[right];
        int k = 1;
        while (left < right && q * k <= D) {
            ++left;
            ++k;
        }
        if (q * k > D) {
            ++wins;
        } else {
            break;
        }
        --right;
    }
 
    cout << wins << endl;
 
    return 0;
}