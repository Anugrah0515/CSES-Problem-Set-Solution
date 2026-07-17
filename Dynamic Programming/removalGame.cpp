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
    vector<int> a(n);
    input(a, n);

    // memoization
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    function<int(int, int)> f = [&](int i, int j) {
        if (i == j) return a[i];
        return max(a[i] - f(i + 1, j), a[j] - f(i, j - 1));
    };

    // tabulation
    for(int i=0;i<n;i++) 
        dp[i][i] = a[i];
    for(int len=2;len<=n;len++) {
        for(int i=0;i + len - 1<n;i++) {
            int j = i + len - 1;
            dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }
    ll total = 0;
    for(auto it: a)
        total += 1LL * it; 
    ll diff = dp[0][n - 1];
    ll ans = (diff + total) / 2LL;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}