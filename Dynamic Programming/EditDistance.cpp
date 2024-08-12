#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define sort(a) sort(a.begin(), a.end())

int memoization(int i, int j, int n, int m, string s, string t, vector<vector<int>>& dp) {
    if (i == n) return m - j;
    if (j == m) return n - i;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == t[j]) return dp[i][j] = memoization(i + 1, j + 1, n, m, s, t, dp);
    else {
        int add = memoization(i, j + 1, n, m, s, t, dp);
        int remove = memoization(i + 1, j, n, m, s, t, dp);
        int replace = memoization(i + 1, j + 1, n, m, s, t, dp);
        return dp[i][j] = 1 + min({add, remove, replace});
    }
}

int tabulation(int n, int m, string s, string t, vector<vector<int>>& dp) {
    for(int i = n; i >= 0; i--) {
        for(int j = m; j >= 0; j--) {
            if (i == n) dp[i][j] = m - j;
            else if (j == m) dp[i][j] = n - i;
            else if (s[i] == t[j]) dp[i][j] = dp[i + 1][j + 1];
            else {
                int add = dp[i][j + 1];
                int remove = dp[i + 1][j];
                int replace = dp[i + 1][j + 1];
                dp[i][j] = 1 + min({add, remove, replace});
            }
        }
    }
    return dp[0][0];
}

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << tabulation(n, m, s, t, dp) << endl;
    return 0;
}
