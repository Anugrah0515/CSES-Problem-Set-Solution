#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define sort(a) sort(a.begin(), a.end())

int memoization(int coinSum, int lastCoin, int n, vector<int>& a, vector<vector<int>>& dp)  {
    if (coinSum == 0) return 1;
    if (lastCoin == n) return 0;
    if (dp[coinSum][lastCoin] != -1) return dp[coinSum][lastCoin];
    int pick = 0, notPick;
    if (coinSum >= a[lastCoin]) pick = memoization(coinSum - a[lastCoin], lastCoin, n, a, dp) % mod;
    notPick = memoization(coinSum, lastCoin + 1, n, a, dp) % mod;
    return dp[coinSum][lastCoin] = (pick + notPick) % mod;
}

int tabulation(int n, int x, vector<int>& a, vector<vector<int>>& dp) {
    for(int i = 0; i <= n; i++) 
        dp[0][i] = 1;  
    for(int coinSum = 1; coinSum <= x; coinSum++) {
        for(int lastCoin = n - 1; lastCoin >= 0; lastCoin--) {
            int pick = 0, notPick;
            if (coinSum >= a[lastCoin]) pick = dp[coinSum - a[lastCoin]][lastCoin] % mod;
            notPick = dp[coinSum][lastCoin + 1] % mod;
            dp[coinSum][lastCoin] = (pick + notPick) % mod;
        }
    }
    return dp[x][0];
}

int optimiation(int n, int x, vector<int>& a, vector<int>& dp) {
    dp[0] = 1;
    for(int i=0;i<n;i++) {
        for(int j=a[i];j<=x;j++) {
            if (j - a[i] >= 0) {
                dp[j] = (dp[j] + dp[j - a[i]]) % mod;
            }
        }
    }
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &it: a) 
        cin >> it;
    sort(a);
    vector<int> dp(x + 1);
    cout << optimiation(n, x, a, dp) << endl;
    return 0;
}
