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

    int sum = ((n + 1) * n) / 2;
    // memoization
    vector<vector<int>> dp(n + 2, vector<int>(sum / 2 + 1, -1));
    function<int(int, int)> f = [&](int i, int target) {
        if (target == 0) return 1;
        if (i > n) return 0;
        if (dp[i][target] != -1) return dp[i][target];
        int take = 0, notTake = 0;
        if (i <= n) notTake = f(i + 1, target);
        if (i <= n && target - i >= 0) take = f(i + 1, target - i);
        return dp[i][target] = (take + notTake) % MOD;
    };

    if (sum % 2) {
        cout << 0 << endl;
        return;
    }
    // this is a step to avoid division by two which can give fals values
    // 1 is going to be in either of the set so just counting them
    cout << f(2, sum / 2 - 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}