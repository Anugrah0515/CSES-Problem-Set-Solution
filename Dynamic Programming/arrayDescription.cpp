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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    input(a, n);

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    function<int(int, int)> f = [&](int i, int last) {
        if (i == n) return 1;
        if (dp[i][last] != -1) return dp[i][last];
        if (a[i] == 0) {
            int ans = 0;
            for(int x = -1;x<=1;x++) {
                int newNumber = last + x;
                if (newNumber >= 1 && newNumber <= m) 
                    ans = (ans + f(i + 1, newNumber)) % MOD;
            }
            return dp[i][last] = ans % MOD;
        } else if (abs(a[i] - last) > 1) 
            return dp[i][last] = 0;
        else
            return dp[i][last] = f(i + 1, a[i]); 
    };
    int ans = 0;
    if (a[0] == 0) {
        for(int i=1;i<m+1;i++) 
            ans = (ans + f(1, i)) % MOD;
        ans = ans % MOD;
    } else 
        ans = f(1, a[0]);
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