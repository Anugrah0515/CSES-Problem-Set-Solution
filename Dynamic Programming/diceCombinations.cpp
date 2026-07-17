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
    
    // memoization
    vector<int> dp(n + 1, -1);
    function<int(int)> f = [&](int sum) {
        if (sum == n) return 1;
        if (dp[sum] != -1) return dp[sum];
        int ways = 0;
        for(int i=1;i<=6;i++) {
            if (i + sum <= n)  
                ways = (ways + f(sum + i)) % MOD;
        }
        return dp[sum] = ways;
    };

    // tabulation
    dp[n] = 1;
    for(int sum=n-1;sum>=0;sum--) {
        int ways = 0;
        for(int i=1;i<=6;i++) {
            if (i + sum <= n)  
                ways = (ways + dp[sum + i]) % MOD;
        }
        dp[sum] = ways;
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