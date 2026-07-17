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
    string s, t;
    cin >> s >> t;
    
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<int> curr(m + 1), ahead(m + 1);

    // memoization
    function<int(int, int)> f = [&](int i, int j) {
        if (j == m) return n - i;
        if (i == n) return m - j;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]) {
            return dp[i][j] = f(i + 1, j + 1);
        } else {
            return dp[i][j] = 1 + min({f(i + 1, j + 1), f(i + 1, j), f(i, j + 1)});
        }
    };

    // tabulation
    for(int i=0;i<=n;i++)
        dp[i][m] = n - i;
    for(int j=0;j<=m;j++)
        dp[n][j] = m - j;
    for(int i=n-1;i>=0;i--) {
        for(int j=m-1;j>=0;j--) {
            dp[i][j] = ((s[i] == t[j]) ? dp[i + 1][j + 1] : 1 + min({dp[i + 1][j + 1], dp[i + 1][j], dp[i][j + 1]}));
        }
    }

    // space optimization
    for(int i=0;i<=m;i++)
        ahead[i] = m - i;
    for(int i=n-1;i>=0;i--) {
        curr[m] = n - i;
        for(int j=m-1;j>=0;j--) {
            curr[j] = ((s[i] == t[j]) ? ahead[j + 1] : 1 + min({ahead[j + 1], ahead[j], curr[j + 1]}));
        }
        ahead = curr;
    }

    cout << ahead[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}