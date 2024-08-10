#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)

int memoization(int target, vector<int>& dp) {
    if (target == 0) return 1;
    if (dp[target] != -1) return dp[target];
    int count = 0;
    for(int i=1;i<=6;i++) {
        if (i <= target) {
            count = (count + memoization(target - i, dp)) % mod;
        }
    }
    return dp[target] = count;
}

int tabulation(int n, vector<int>& dp) {
    dp[0] = 1;
    for(int target = 1;target<=n;target++) {
        int count = 0;
        for(int i=1;i<=6;i++) {
            if (i <= target) {
                count = (count + dp[target - i]) % mod;
            }
        }
        dp[target] = count;
    }
    return dp[n];
}

int main() {
    int n;
    cin>>n;
    vector<int> dp(n + 1);
    cout<<tabulation(n, dp)<<endl;
    return 0;
}