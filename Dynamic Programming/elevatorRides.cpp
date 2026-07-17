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
    vector<pair<int, int>> dp(1 << n);
    vector<bool> vis(1 << n);
    function<pair<int, int>(int)> f = [&](int mask) -> pair<int, int> {
        if (mask == 0) return {1, 0};
        if (vis[mask]) return dp[mask];
        vis[mask] = true;
        pair<int, int> best = {INT_MAX, INT_MAX};
        for(int i=0;i<n;i++) {
            if (mask & (1 << i)) {
                pair<int, int> curr = f(mask ^ (1 << i));
                if (curr.second + a[i] <= x) {
                    curr.second += a[i];
                } else {
                    curr.first++;
                    curr.second = a[i];
                }
                best = min(best, curr);
            }
        }
        return dp[mask] = best;
    };
    cout << f((1 << n) - 1).first << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}