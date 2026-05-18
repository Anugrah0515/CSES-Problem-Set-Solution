#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define input(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define output(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define sort(a) sort(a.begin(), a.end());
#define reverse(a) reverse(a.begin(), a.end());

set<string> ans;

void f(string s, string str, int mask, int n) {
    if (mask == (1 << n) - 1) {
        ans.insert(str);
        return;
    }
    for(int i=0;i<n;i++) {
        if (mask & (1 << i)) continue;
        str += s[i];
        f(s, str, mask | (1 << i), n);
        str.pop_back();
    }
    return;
}

void solve() {
    string s;
    cin >> s;

    sort(s);
    string str = "";
    int mask = 0;
    f(s, str, mask, s.size());
    cout << ans.size() << endl;
    for (auto str: ans) {
        cout << str << endl;
    }
    return;
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