#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define input(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define output(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define sort(a) sort(a.begin(), a.end());
#define reverse(a) reverse(a.begin(), a.end());

void f(ll a, ll b, ll c, ll n) {
    if(n == 0) return;

    f(a, c, b, n - 1);
    cout << a << " " << c << endl;
    f(b, a, c, n - 1);
}

void solve() {
    ll n;
    cin >> n;
    
    ll ans = (1ll << n) - 1;
    cout << ans << endl;
    f(1, 2, 3, n);
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