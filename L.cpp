#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        string row1, row2;
        cin >> row1 >> row2;
        
        vector<vector<char>> grid(2, vector<char>(n));
        
        for (int i = 0; i < n; i++) {
            grid[0][i] = row1[i];
            grid[1][i] = row2[i];
        }
        
        bool possible = true;
        
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == '<' && i % 2 == 1) {
                if (grid[1][i - 1] == '<' || (i <= n - 2 && grid[1][i + 1] == '<')) {
                    possible = false;
                    break;
                }
            }
        }
        
        if (possible) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}