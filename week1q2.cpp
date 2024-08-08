#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }
                if (c == ')' && st.top() == '(') {
                    st.pop();
                } else if (c == '}' && st.top() == '{') {
                    st.pop();
                } else if (c == ']' && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution sol;
        cout << (sol.isValid(s) ? "true" : "false") << endl;
    }
    return 0;
}