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
vector<vector<ll>> dp(1e6 + 1, vector<ll>(2));

void solve() {
    int n;
    cin >> n;

    cout << (dp[n][0] + dp[n][1]) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    // memoization
    function<ll(int, int)> f = [&](int i, int last) -> ll {
        if (i == 1) return 1;
        if (dp[i][last] != -1) return dp[i][last];
        if (last == 1) return dp[i][last] = ((f(i - 1, 1) * 4) % MOD + f(i - 1, 0)) % MOD;
        else return dp[i][last] = (f(i - 1, 1) + (2 * f(i - 1, 0)) % MOD) % MOD;
    };

    // tabulation
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2;i<=1e6;i++) {
        dp[i][0] = (dp[i - 1][1] + (2LL * dp[i - 1][0])) % MOD;
        dp[i][1] = ((4LL * dp[i - 1][1])+ dp[i - 1][0]) % MOD;
    }

    while (t--) solve();

    return 0;
}