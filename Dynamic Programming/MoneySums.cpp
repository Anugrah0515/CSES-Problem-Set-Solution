#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define sort(a) sort(a.begin(), a.end())

int memoization(int i, int target, int n, vector<int>& a, vector<vector<int>>& dp, set<int>& st) {
    if (target != 0) st.insert(target);
    if (i == n) return target == 0;
    if (dp[i][target] != -1) return dp[i][target];
    int take = 0, notTake = 0;
    if(a[i] <= target) take = take || memoization(i + 1, target - a[i], n, a, dp, st);
    notTake = notTake || memoization(i + 1, target, n, a, dp, st);
    return dp[i][target] = take || notTake;
}

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &it: a)
        cin>>it;
    int maxSum = 0;
    for(auto it: a)
        maxSum += it;
    set<int> st;
    vector<vector<int>> dp(n + 1, vector<int>(maxSum + 1, -1));
    memoization(0, maxSum, n, a, dp, st);
    cout<<st.size()<<endl;
    for(auto it: st)
        cout<<it<<" ";
    cout<<endl;
    return 0;    
}