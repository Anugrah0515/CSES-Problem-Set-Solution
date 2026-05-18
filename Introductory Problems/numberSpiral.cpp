#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define input(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define output(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
#define sort(a) sort(a.begin(), a.end());
#define reverse(a) reverse(a.begin(), a.end());

void solve() {
    ll x, y;
    cin >> y >> x;

    ll ans = 0;
    if (x <= y) {
        ll ay = (y % 2 ? (y - 1) * (y - 1) + 1 : y * y);
        x--;
        if (y % 2) ans = ay + x;
        else ans = ay - x;
    } else {
        ll ax = (x % 2 ? x * x : (x - 1) * (x - 1) + 1);
        y--;
        if (x % 2) ans = ax - y;
        else ans = ax + y;
    }

    cout << ans << endl;

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}