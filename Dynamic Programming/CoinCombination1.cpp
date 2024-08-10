#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define sort(a) sort(a.begin(), a.end())

int memoization(int coinSum, vector<int>& a, vector<int>& dp) {
    if (coinSum == 0) return 1;
    if (dp[coinSum] != -1) return dp[coinSum];
    int ans = 0;
    for(auto it: a) {
        if (it <= coinSum) {
            ans = (ans + memoization(coinSum - it, a, dp)) % mod;
        }
    }
    return dp[coinSum] = ans;
}

int tabulation(int x, vector<int>& a, vector<int>& dp) {
    dp[0] = 1;
    for(int coinSum = 1;coinSum <= x;coinSum++) {
        int ans = 0;
        for(auto it: a) {
            if (it <= coinSum) {
                ans = (ans + dp[coinSum - it]) % mod;
            }
        }
        dp[coinSum] = ans;
    }
    return dp[x];
}

int main() {
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    for(auto &it: a)
        cin>>it;
    vector<int> dp(x + 1, 0);
    cout<<tabulation(x, a, dp)<<endl;
    return 0;
}