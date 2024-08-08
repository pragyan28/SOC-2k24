#include<bits/stdc++.h>
using namespace std;

int count(string str, int k)
{
    int n = str.length();

    int res = 0;
    int cnt[26];
    for (int i = 0; i < n; i++)
    {
        int d = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int j=i; j<n; j++)
        {
            if (cnt[str[j] - 'a'] == 0)
            d++;
            cnt[str[j] - 'a']++;
            if (d == k)
                res++;
            if(d > k) break;
        }
    }

    return res;
}

// Driver Program
int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin>>k;
        string str;
        cin >> str;
        cout << count(str, k) << endl;
    }
    return 0;
}