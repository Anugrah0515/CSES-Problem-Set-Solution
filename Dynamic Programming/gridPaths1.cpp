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
    vector<vector<char>> grid(n, vector<char>(n));
    for(auto &it: grid)
        for(auto &ch: it)
            cin >> ch;

    // memoization
    vector<vector<int>> dp(n, vector<int>(n));
    function<int(int, int)> f = [&](int r, int c) {
        if (r == n - 1 && c == n - 1) return 1;
        if (dp[r][c] != -1) return dp[r][c];
        int right = (c < n - 1 && grid[r][c + 1] != '*' ? f(r, c + 1) : 0);        
        int down = (r < n - 1 && grid[r + 1][c] != '*' ? f(r + 1, c) : 0);        
        return dp[r][c] = (right + down) % MOD;
    };

    // tabulation
    if (grid[n - 1][n - 1] == '*' || grid[0][0] == '*') {
        cout << 0 << endl;
        return;
    }
    for(int i=n-1;i>=0;i--)
        if (grid[i][n - 1] == '.') 
            dp[i][n - 1] = 1;
        else 
            break;
    for(int i=n-1;i>=0;i--)
        if (grid[n - 1][i] == '.') 
            dp[n - 1][i] = 1;
        else 
            break;

    for(int r = n - 2;r>=0;r--) {
        for(int c=n - 2;c>=0;c--) {
            int right = (grid[r][c + 1] != '*' ? dp[r][c + 1] : 0);        
            int down = (grid[r + 1][c] != '*' ? dp[r + 1][c] : 0);        
            dp[r][c] = (right + down) % MOD;
        }
    }

    cout << dp[0][0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}