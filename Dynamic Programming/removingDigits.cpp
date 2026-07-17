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
    function<int(int)> f = [&](int sum) -> int {
        if (sum == 0) return 0;
        if (dp[sum] != -1) return dp[sum];
        int ans = 1e9;
        int x = sum;
        while(x) {
            if (x % 10 && x % 10 <= sum)
                ans = min(ans, 1 + f(sum - x % 10));
            x /= 10;
        }
        return dp[sum] = ans;
    };

    // tabulation
    dp[0] = 0;
    for(int sum = 1;sum<=n;sum++) {
        int ans = 1e9;
        int x = sum;
        while(x) {
            if (x % 10 && x % 10 <= sum)
                ans = min(ans, 1 + dp[sum - x % 10]);
            x /= 10;
        }
        dp[sum] = ans;
    }

    cout << dp[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}