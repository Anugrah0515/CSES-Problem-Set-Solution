#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)

int memoization(int i, int endDate, int n, vector<vector<int>>& a, vector<vector<int>>& dp) {
    if (i == n) return 0;
    if (dp[i][endDate + 1] != -1) return dp[i][endDate + 1];
    int take = -1e9, notTake = memoization(i + 1, endDate, n, a, dp);
    if (endDate == -1 || a[i][0] > a[endDate][1]) take = a[i][2] + memoization(i + 1, i, n, a, dp);
    return dp[i][endDate + 1] = max(take, notTake);
}

int tabulation(int n, vector<vector<int>>& a, vector<vector<int>>& dp) {
    for(int i=n-1;i>=0;i--) {
        for(int endDate=i-1;endDate>=-1;endDate--) {
            int take = -1e9, notTake = dp[i + 1][endDate + 1];
            if (endDate == -1 || a[i][0] > a[endDate][1]) take = a[i][2] + dp[i + 1][i + 1];
            dp[i][endDate + 1] = max(take, notTake);
        }
    }
    return dp[0][0];
}

ll spaceOptimization(int n, vector<vector<int>>& a) {
    vector<ll> ahead(n + 2), curr(n + 2);
    for(int i=n-1;i>=0;i--) {
        for(int endDate=i-1;endDate>=-1;endDate--) {
            ll take = -1e9, notTake = ahead[endDate + 1];
            if (endDate == -1 || a[i][0] > a[endDate][1]) take = a[i][2] + ahead[i + 1];
            curr[endDate + 1] = max(take, notTake);
        }
        ahead = curr;
    }
    return curr[0];
}

int lastNonOverlappingInterval(vector<vector<int>>& a, int index) {
    int low = 0, high = index - 1;
    int targetStartDate = a[index][0];
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if (targetStartDate > a[mid][1]) {
            if (targetStartDate > a[mid + 1][1]) low = mid + 1;
            else return mid;
        } else high = mid - 1;
    }
    return -1;
}

// here greedy is basically dp + binary search
ll greedy(int n, vector<vector<int>>& a) {
    sort(a.begin(), a.end(), [](auto& x, auto& y) {
        return x[1] < y[1];
    });
    vector<ll> dp(n, 0);
    dp[0] = a[0][2];
    for(int i=1;i<n;i++) {
        ll reward = a[i][2];
        int lastRewardIndex = lastNonOverlappingInterval(a, i);
        if (lastRewardIndex != -1) {
            reward += dp[lastRewardIndex];
        }
        dp[i] = max(dp[i - 1], reward);
    }
    return dp[n-1];
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(3));
    for(auto &it: a) 
        for(auto &x: it) 
            cin>>x;
    // vector<vector<int>> dp(n + 1, vector<int>(n + 2));
    cout<<greedy(n, a)<<endl;
    return 0;
}