#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)

ll memoization(int i, ll target, vector<vector<ll>>& dp) {
    if (i == 0) return target == 0;
    if (dp[i][target] != -1) return dp[i][target];
    int take = 0, notTake = memoization(i - 1, target, dp) % mod;
    if (target >= i) take = memoization(i - 1, target - i, dp) % mod;
    return dp[i][target] = (take + notTake) % mod;
}

ll tabulation(int n, int totalSum, vector<vector<ll>>& dp) {
    dp[0][0] = 1;
    for(int i=1;i<=n;i++) {
        for(int target = 1;target<=totalSum;target++) {
            int take = 0, notTake = dp[i - 1][target] % mod;
            if (target >= i) take = dp[i - 1][target - i] % mod;
            dp[i][target] = (take + notTake) % mod;
        }
    }
    return dp[n][totalSum];
}

ll sapceOptimised(int n, int totalSum) {
    vector<ll> curr(totalSum + 1), prev(totalSum + 1);
    prev[0] = 1;
    for(int i=1;i<=n;i++) {
        for(int target = 1;target<=totalSum;target++) {
            int take = 0, notTake = prev[target] % mod;
            if (target >= i) take = prev[target - i] % mod;
            curr[target] = (take + notTake) % mod;
        }
        prev = curr;
    }
    return curr[totalSum];
}

int main() {
    int n;
    cin >> n;
    ll totalSum = (n * (n + 1)) / 2;
    vector<vector<ll>> dp(n + 1, vector<ll>(totalSum / 2 + 1));
    if (totalSum % 2) cout<<0<<endl;
    else cout<<sapceOptimised(n, totalSum / 2)<<endl;
    return 0;
}
