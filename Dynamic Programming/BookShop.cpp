#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define sort(a) sort(a.begin(), a.end())

int memoization(int i, int price, int n, vector<pair<int, int>>& a, vector<vector<int>>& dp) {
    if (i == n) return 0;
    if (price == 0) return 0;
    if (dp[i][price] != -1) return dp[i][price];
    int take = -1e9, notTake = memoization(i + 1, price, n, a, dp);
    if (price >= a[i].first)
        take = a[i].second + memoization(i + 1, price - a[i].first, n, a, dp);
    return dp[i][price] = max(take, notTake);
}

int tabulation(int n, int x, vector<pair<int, int>>& a, vector<vector<int>>& dp) {
    for(int i=0;i<n;i++) 
        dp[i][0] = 0;
    for(int i=0;i<=x;i++)
        dp[n][i] = 0;
    for(int i=n-1;i>=0;i--) {
        for(int price=1;price<=x;price++) {
            int take = -1e9, notTake = dp[i + 1][price];
            if (price >= a[i].first)
                take = a[i].second + dp[i + 1][price - a[i].first];
            dp[i][price] = max(take, notTake);
        }
    }
    return dp[0][x];
}

int spaceOptimization(int n, int x, vector<pair<int, int>>& a, vector<int>& curr, vector<int>& ahead) {
    for(int i=n-1;i>=0;i--) {
        for(int price=1;price<=x;price++) {
            int take = -1e9, notTake = ahead[price];
            if (price >= a[i].first)
                take = a[i].second + ahead[price - a[i].first];
            curr[price] = max(take, notTake);
        }
        ahead = curr;
    }
    return curr[x];
}

int main() {
    int n, x;
    cin>>n>>x;
    vector<pair<int, int>> a(n);
    for(auto &it: a) 
        cin>>it.first;
    for(auto &it: a)
        cin>>it.second;
    vector<int> curr(x + 1), ahead(x + 1);
    cout<<spaceOptimization(n, x, a, curr, ahead)<<endl;
    return 0;
}
