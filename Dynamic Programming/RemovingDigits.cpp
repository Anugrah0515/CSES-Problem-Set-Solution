#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define sort(a) sort(a.begin(), a.end())

int memoiation(int i, vector<int>& dp) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    int ans = 1e9, temp = i;
    set<int> digits;
    while(temp > 0) {
        digits.insert(temp % 10);
        temp /= 10;
    }
    for(auto it: digits) {
        if (it != 0 && it <= i) {
            ans = min(ans, 1 + memoiation(i - it, dp));
        }
    }
    return dp[i] = ans;
}

int tabulation(int n, vector<int>& dp) {
    dp[0] = 0;
    for(int i=1;i<=n;i++) {
        int ans = 1e9, temp = i;
        set<int> digits;
        while(temp > 0) {
            digits.insert(temp % 10);
            temp /= 10;
        }
        for(auto it: digits) {
            if (it != 0 && it <= i) {
                ans = min(ans, 1 + dp[i - it]);
            }
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main() {
    int n;
    cin>>n;
    vector<int> dp(n + 1, -1);
    cout<<tabulation(n, dp)<<endl;
    return 0;
}
