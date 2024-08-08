#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> notes(n);
        for (int i = 0; i < n; i++) {
            cin >> notes[i];
        } 
 
        vector<int> differences(n - 1);
        for (int i = 0; i < n - 1; i++) {
            differences[i] = notes[i + 1] - notes[i];
        }
 
        long long totalDifference = 0;
        for (int i = 0; i < n / 2; i++) {
            totalDifference += differences[2 * i];
        }
 
        if (n % 2 == 1) {
            cout << "YES" << endl;
        } else {
            if (totalDifference >= 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
 
    return 0;
}