#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define sort(a) sort(a.begin(), a.end())

int memoization(int i, int last, int n, vector<int>& a, vector<vector<int>>& dp) {
    if (i == n) return 0;
    if (dp[i][last + 1] != -1) return dp[i][last + 1];
    int take = -1e9, notTake = memoization(i + 1, last, n, a, dp);
    if (last == -1 || a[i] > a[last])
        take = 1 + memoization(i + 1, i, n, a, dp);
    return dp[i][last + 1] = max(take, notTake);
}

int tabulation(int n, vector<int>& a, vector<vector<int>>& dp) {
    for(int i=n-1;i>=0;i--) {
        for(int last = i-1;last>=-1;last--) {
            int pick = INT_MIN, notPick;
            if ( last == -1 || a[i] > a[last]) pick = 1 + dp[i + 1][i+1];
            notPick = dp[i + 1][last+1];
            dp[i][last+1] = max(notPick, pick);
        }
    }
    return dp[0][0];
}

int spaceOptimization(int n, vector<int>& a) {
    vector<int> curr(n+1), ahead(n+1);
    for(int i=n-1;i>=0;i--) {
        for(int last = i-1;last>=-1;last--) {
            int pick = INT_MIN, notPick;
            if ( last == -1 || a[i] > a[last]) pick = 1 + ahead[i+1];
            notPick = ahead[last+1];
            curr[last+1] = max(notPick, pick);
        }
        ahead = curr;
    }
    return ahead[0];
}

int bestApproach(int n, vector<int>& a) {
    vector<int> lis;
    lis.push_back(a[0]);
    for(int i=1;i<n;i++) {
        if (lis.back() >= a[i]) {
            int index = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[index] = a[i];
        } else {
            lis.push_back(a[i]);
        }
    }
    return lis.size();
}

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &it: a) 
        cin>>it;
    // vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
    cout<<bestApproach(n, a)<<endl;
    return 0;
}