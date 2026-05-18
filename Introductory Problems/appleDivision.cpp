#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define input(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define output(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define sort(a) sort(a.begin(), a.end());
#define reverse(a) reverse(a.begin(), a.end());

ll f(ll i, ll a, ll b, vector<ll>& v, ll n) {
    if (i == n) return abs(a - b);
    return min(f(i + 1, a + v[i], b, v, n), f(i + 1, a, b + v[i], v, n));
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    input(a, n);

    cout << f(0, 0, 0, a, n) << endl;
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