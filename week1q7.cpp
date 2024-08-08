#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n ;
         int h=0;
     for(int x=0; x<=n; x++){
            if((n+x)==(n^x)) h++;
        }
        cout<< h;
        return 0;
    }
    
}