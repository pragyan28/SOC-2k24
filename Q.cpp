#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0);
 
int main() {
    IOS;
    ll t;
    cin >> t;
    while (t--) {
        int length;
        cin >> length;
        string rows[2];
        cin >> rows[0] >> rows[1];
 
        string result = "";
        int current_row = 0;
        int answer = 1;
 
        for (int index = 0; index < length; index++) {
            if (index == length - 1) {
                if (current_row == 0) {
                    result += rows[0][index];
                    result += rows[1][index];
                } else {
                    result += rows[1][index];
                }
                continue;
            }
 
            if (current_row == 1) {
                result += rows[current_row][index];
            } else {
                result += rows[current_row][index];
                if (rows[current_row][index + 1] == rows[current_row + 1][index]) {
                    answer += 1;
                } else {
                    if (rows[current_row][index + 1] == '0') {
                        answer = 1;
                    } else {
                        current_row = 1;
                        index--;
                    }
                }
            }
        }
        cout << result << "\n";
        cout << answer << "\n";
    }
    return 0;
}