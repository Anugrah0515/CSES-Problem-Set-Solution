#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define sort(a) sort(a.begin(), a.end())

int memoization(int a, int b, vector<vector<int>>& dp) {
    if (a == b) return 0;
    if (a == 1) return b - 1;
    if (b == 1) return a - 1;
    if (dp[a][b] != INT_MAX) return dp[a][b];
    int ans = INT_MAX;
    for(int i=1;i<a;i++) {
        ans = min(ans, 1 + memoization(i, b, dp) + memoization(a - i, b, dp));
    }
    for(int i=1;i<b;i++) {
        ans = min(ans, 1 + memoization(a, i, dp) + memoization(a, b - i, dp));
    }
    return dp[a][b] = ans;
}

int tabulation(int n, int m, vector<vector<int>>& dp) {
    for(int a=0;a<=n;a++) {
        for(int b=0;b<=m;b++) {
            if (a == b) {
                dp[a][b] = 0;
            } else {
                int ans = INT_MAX;
                for(int i=1;i<a;i++) {
                    ans = min(ans, 1 + dp[i][b] + dp[a - i][b]);
                }
                for(int i=1;i<b;i++) {
                    ans = min(ans, 1 + dp[a][i] + dp[a][b - i]);
                }
                dp[a][b] = ans;
            }
        }
    }
    return dp[n][m];
}

int main() {
    int a, b;
    cin>>a>>b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));
    cout<<memoization(a, b, dp)<<endl;
    return 0;
}