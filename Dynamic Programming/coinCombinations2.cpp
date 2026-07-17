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
    int x, n;
    cin >> n >> x;
    vector<int> a(n);
    input(a, n);

    // memoization
    vector<vector<int>> dp(n + 1, vector<int>(1e6 + 1, -1));
    function<int(int, int)> f = [&](int i, int sum) -> int {
        if (sum == 0) return 1;
        if (i == n) return 0;
        if (dp[i][sum] != -1) return dp[i][sum];
        int take = 0, notTake = f(i + 1, sum);
        if (sum >= a[i])
            take = f(i, sum - a[i]);
        return dp[i][sum] = (take + notTake) % MOD;
    };

    // tabulation
    for(int i=0;i<n;i++)
        dp[i][0] = 1;
    for(auto &it: dp[n])
        it = 0; 
    for(int i = n-1;i>=0;i--) {
        for(int sum = 1;sum <= x;sum ++) {
            int take = 0, notTake = dp[i + 1][sum];
            if (sum >= a[i])
                take = dp[i][sum - a[i]];
            dp[i][sum] = (take + notTake) % MOD;
        }
    }

    // space optimization
    vector<int> curr(1e6 + 1), ahead(1e6 + 1);
    ahead[0] = curr[0] = 1;
    for(int i = n-1;i>=0;i--) {
        for(int sum = 1;sum <= x;sum ++) {
            int take = 0, notTake = ahead[sum];
            if (sum >= a[i])
                take = curr[sum - a[i]];
            curr[sum] = (take + notTake) % MOD;
        }
        ahead = curr;
    }

    cout << curr[x] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}