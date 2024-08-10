#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define sort(a) sort(a.begin(), a.end())

int memoization(int i, int prev, int n, int m, vector<int>& a, vector<vector<int>>& dp) {
    if (i == n) return 1;
    if (dp[i][prev] != -1) return dp[i][prev];
    int total = 0;
    if (a[i] != 0) {
        if (prev == 0 || abs(a[i] - prev) <= 1) {
            total = memoization(i + 1, a[i], n, m, a, dp);
        }
    } else {
        for (int val = 1; val <= m; val++) {
            if (prev == 0 || abs(val - prev) <= 1) {
                total = (total + memoization(i + 1, val, n, m, a, dp)) % mod;
            }
        }
    }
    return dp[i][prev] = total;
} 

int tabulation(int n, int m, vector<int>& a, vector<vector<int>>& dp) {
    for(int i=0;i<m+2;i++)
        dp[n][i] = 1;
    for(int i=n-1;i>=0;i--) {
        for(int prev=m;prev>=0;prev--) {
            int total = 0;
            if (a[i] != 0) {
                if (prev == 0 || abs(a[i] - prev) <= 1) {
                    total = dp[i + 1][a[i]];
                }
            } else {
                for (int val = 1; val <= m; val++) {
                    if (prev == 0 || abs(val - prev) <= 1) {
                        total = (total + dp[i + 1][val]) % mod;
                    }
                }
            }
            dp[i][prev] = total;
        }
    }
    return dp[0][0];
}

int spaceOptimized(int n, int m, vector<int>& a) {
    vector<int> curr(m + 1, 0), ahead(m + 1, 1);
    for (int i = n - 1; i >= 0; i--) {
        for (int prev = 0; prev <= m; prev++) {
            int total = 0;
            if (a[i] != 0) {
                if (prev == 0 || abs(a[i] - prev) <= 1) {
                    total = ahead[a[i]];
                }
            } else {
                for (int val = 1; val <= m; val++) {
                    if (prev == 0 || abs(val - prev) <= 1) {
                        total = (total + ahead[val]) % mod;
                    }
                }
            }
            curr[prev] = total;
        }
        ahead = curr;
    }
    return curr[0];
}

int bestSolution(int n, int m, vector<int>& a) {
    vector<vector<ll>> dp(n, vector<ll>(m + 2, 0));
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (a[i] == 0) {
                for (int val = 1; val <= m; val++)
                    dp[i][val] = 1;
            }
            else {
                dp[i][a[i]] = 1;
            }
        } else {
            if (a[i] == 0) {
                for (int val = 1; val <= m; val++) {
                    dp[i][val] = (dp[i - 1][val - 1] + dp[i - 1][val] + dp[i - 1][val + 1]) % mod;
                }
            } else {
                dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) % mod;
            }
        }
    }
    ll ans = 0;
    for (int val = 1; val <= m; val++) {
        ans = (ans + dp[n - 1][val]) % mod;
    }
    return ans;
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(auto &it: a)
        cin>>it;
    vector<vector<int>> dp(n + 1, vector<int>(m + 2));
    cout<<bestSolution(n, m, a)<<endl;    
    return 0;
}