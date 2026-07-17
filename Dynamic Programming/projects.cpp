#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define input(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define output(a) for (auto it : a) cout << it << " ";
#define sortFcn(a) sort(a.begin(), a.end());
#define rev(a) reverse(a.begin(), a.end());
#define lowerBound(a, x) lower_bound(a.begin(), a.end(), x)
#define upperBound(a, x) upper_bound(a.begin(), a.end(), x)
#define impossible cout << "IMPOSSIBLE" << endl;

int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<ll>> a;
    for(int i=0;i<n;i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        a.pb({x, y, z});
    }

    vector<ll> dp(n + 1, -1);
    sortFcn(a);
    function<ll(int)> f = [&](int i) -> ll {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        ll take = 0, notTake = f(i + 1);
        auto it = lower_bound(a.begin(), a.end(), a[i][1] + 1, [](const vector<ll>& v, ll val) {
                return v[0] < val;
            });
        int idx = it - a.begin();
        take = a[i][2] + f(idx);
        return dp[i] = max(take, notTake);
    };

    dp[n] = 0;
    for(int i=n-1;i>=0;i--) {
        ll take = 0, notTake = dp[i + 1];
        auto it = lower_bound(a.begin(), a.end(), a[i][1] + 1, [](const vector<ll>& v, ll val) {
                return v[0] < val;
            });
        int idx = it - a.begin();
        if (idx <= n) take = a[i][2] + dp[idx];
        dp[i] = max(take, notTake);
    }
    cout << dp[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}