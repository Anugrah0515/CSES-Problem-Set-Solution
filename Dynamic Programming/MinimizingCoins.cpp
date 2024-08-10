#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define sort(a) sort(a.begin(), a.end())

int memoization(int coinSum, vector<int>& a, vector<int>& dp) {
    if (coinSum == 0) return 0;
    if (dp[coinSum] != -1) return dp[coinSum];
    int ans = 1e9;
    for(auto it: a) {
        if (it <= coinSum) {
            ans = min(ans, 1 + memoization(coinSum - it, a, dp));
        }
    }
    return dp[coinSum] = ans;
}

int tabulation(int x, vector<int>& a, vector<int>& dp) {
    dp[0] = 0;
    for(int coinSum = 1;coinSum <= x;coinSum++) {
        int ans = 1e9;
        for(auto it: a) {
            if (it <= coinSum) {
                ans = min(ans, 1 + dp[coinSum - it]);
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
    sort(a);
    vector<int> dp(x+1);
    int ans = tabulation(x, a, dp);
    cout<<((ans == 1e9) ? -1 : ans)<<endl;
    return 0;
}