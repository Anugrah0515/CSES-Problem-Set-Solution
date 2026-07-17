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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    input(a, n);

    // memoization
    vector<int> dp(1e6 + 1, -1);
    function<ll(int)> f = [&](int sum) -> ll {
        // if (sum == 0) return 1;
        if (dp[sum] != -1) return dp[sum];
        ll ways = 0;
        for(auto it: a) 
            if (it == sum) 
                return 1;
            else if (sum - it >= 0)
                ways = (ways + f(sum - it)) % MOD;
        return dp[sum] = ways;
    };

    // tabulation
    dp[0] = 1;
    for(int sum=1;sum<=x;sum++) {
        ll ways = 0;
        for(auto it: a) 
            if (sum - it >= 0)
                ways = (ways + dp[sum - it]);
        dp[sum] = ways % MOD;
    }  

    cout << dp[x] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}