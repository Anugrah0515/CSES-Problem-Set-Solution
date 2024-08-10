#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define sort(a) sort(a.begin(), a.end())

ll memoizaztion(int row, int col, int n, vector<vector<char>>& grid, vector<vector<int>>& dp) {
    if (row == 0 && col == 0) return 1;
    if (dp[row][col] != -1) return dp[row][col];
    ll left = 0, top = 0;
    if (row > 0 && grid[row - 1][col] != '*') top = memoizaztion(row - 1, col, n, grid, dp) % mod;
    if (col > 0 && grid[row][col - 1] != '*') left = memoizaztion(row, col - 1, n, grid, dp) % mod;
    return dp[row][col] = (left + top) % mod;
}

int tabulation(int n, vector<vector<char>>& grid, vector<vector<int>>& dp) {
    if (grid[0][0] == '*') return 0;
    dp[0][0] = 1;
    for(int i=1;i<n;i++) {
        if (grid[i][0] != '*') 
            dp[i][0] = dp[i - 1][0];
    }
    for(int i=1;i<n;i++) {
        if (grid[0][i] != '*')
            dp[0][i] = dp[0][i-1];
    }
    for(int row = 1;row<n;row++) {
        for(int col = 1;col<n;col++) {
            if (grid[row][col] == '*') continue;
            ll left = 0, top = 0;
            if (row > 0 && grid[row - 1][col] != '*') top = dp[row - 1][col] % mod;
            if (col > 0 && grid[row][col - 1] != '*') left = dp[row][col - 1] % mod;
            dp[row][col] = (left + top) % mod;
        }
    }
    return dp[n - 1][n - 1];
}

int main() {
    int n;
    cin>>n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(auto &it: grid) 
        for(auto &i: it) 
            cin>>i;
    vector<vector<int>> dp(n, vector<int>(n));
    cout<<tabulation(n, grid, dp)<<endl;
    return 0;
}
