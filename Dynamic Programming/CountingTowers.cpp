#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9 + 7)
#define sort(a) sort(a.begin(), a.end())

int memoization(int i, vector<int>& dp) {
    if (i == 1) return 2;
    if (dp[i] != -1) return dp[i];
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> dp(n, -1);
        cout<<memoization(n, dp)<<endl;
    }
}