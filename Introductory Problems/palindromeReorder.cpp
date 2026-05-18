#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define input(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define output(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
#define sort(a) sort(a.begin(), a.end());
#define reverse(a) reverse(a.begin(), a.end());

void solve() {
    string s;
    cin >> s;

    map<char, int> mp;
    for (auto ch: s)
        mp[ch]++;
    int oddCount = 0;
    for (auto it: mp) {
        if (it.second % 2 != 0)
            oddCount++;
    }
    if (oddCount > 1) {
        cout << "NO SOLUTION" << endl;
        return;
    }
    s = "";
    char oddChar = '*';
    for (auto it: mp) 
        if (it.second % 2 != 0)
            oddChar = it.first;

    for (auto it: mp) {
        if (it.first != oddChar) 
            s += string(it.second / 2, it.first);
    }
    string revStr = s;
    reverse(revStr);
    if (oddChar != '*')
        s += string(mp[oddChar], oddChar);
    s += revStr;

    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}