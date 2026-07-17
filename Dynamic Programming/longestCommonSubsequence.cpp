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
    vector<int> a(n), b(m);
    input(a, n)
    input(b, m)

    // memoization
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    function<int(int, int)> f = [&](int i, int j) {
        if (i == n) return 0;
        if (j == m) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if (a[i] == b[j]) {
            ans = 1 + f(i + 1, j + 1);
        } else {
            ans = max(f(i, j + 1), f(i + 1, j));
        }
        return dp[i][j] = ans;
    };
    
    // tabulation 
    for(int i=n-1;i>=0;i--)
        for(int j=m-1;j>=0;j--) {
            int ans = 0;
            if (a[i] == b[j]) {
                ans = 1 + dp[i + 1][j + 1];
            } else {
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = ans;
        }

    int i = 0, j = 0;
    vector<int> lcs;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            lcs.push_back(a[i]);
            i++;
            j++;
        }
        else if (dp[i + 1][j] >= dp[i][j + 1]) {
            i++;
        }
        else {
            j++;
        }
    }
    
    // space optimization
    vector<int> curr(m + 1), ahead(m + 1);
    for(int i=n-1;i>=0;i--) {
        for(int j=m-1;j>=0;j--) {
            int ans = max(curr[j + 1], ahead[j]);
            if (a[i] == b[j]) {
                ans = max(ans, 1 + ahead[j + 1]);
            }
            curr[j] = ans;
        }
        ahead = curr;
    }
    cout << ahead[0] << endl;
    output(lcs);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}