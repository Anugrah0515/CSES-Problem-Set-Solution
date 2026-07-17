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

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    input(a, n);

    // memoization
    vector<ll> dp(1e6 + 1, -1);
    function<ll(int)> f = [&](int sum) -> ll {
        if (dp[sum] != -1) return dp[sum];
        ll coinCount = 1e9;
        for(auto it: a) 
            if (it == sum) 
                return 1;
            else if (sum - it >= 0)
                coinCount = min(coinCount, 1 + f(sum - it));
        return dp[sum] = coinCount;
    };

    // tabulation
    dp[0] = 0;
    for(auto it: a)
        dp[it] = 1;
    for(int sum=1;sum<=x;sum++) {
        ll coinCount = 1e9;
        for(auto it: a) 
            if (sum - it >= 0)
                coinCount = min(coinCount, 1 + dp[sum - it]);
        dp[sum] = coinCount;
    }  

    cout << (dp[x] == 1e9 ? -1 : dp[x]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}