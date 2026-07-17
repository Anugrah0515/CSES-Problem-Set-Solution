#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define input(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define output(a) for (auto it : a) cout << it << " ";
#define sortFcn(a) sort(a.begin(), a.end());
#define rev(a) reverse(a.begin(), a.end());
#define lowerBound(a, x) lower_bound(a.begin(), a.end(), x)
#define upperBound(a, x) upper_bound(a.begin(), a.end(), x)
#define impossible cout << "IMPOSSIBLE" << endl;

int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> price(n), books(n);
    input(price, n)
    input(books, n)

    // memoization
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    function<int(int, int)> f = [&](int i, int sum) {
        if (sum == 0) return 0;
        if (i == n) return 0;
        if (dp[i][sum] != -1) return dp[i][sum];
        int take = 0, notTake = f(i + 1, sum);
        if (sum >= price[i])
            take = books[i] + f(i + 1, sum - price[i]);
        return dp[i][sum] = max(take, notTake);
    };

    // tabulation
    for(int i = n - 1;i>=0;i--) {
        for(int sum=0;sum<=x;sum++) {
            int take = 0, notTake = dp[i + 1][sum];
            if (sum >= price[i])
                take = books[i] + dp[i + 1][sum - price[i]];
            dp[i][sum] = max(take, notTake);
        }
    }

    // space optimization
    vector<int> curr(x + 1), ahead(x + 1);
    for(int i = n - 1;i>=0;i--) {
        for(int sum=0;sum<=x;sum++) {
            int take = 0, notTake = ahead[sum];
            if (sum >= price[i])
                take = books[i] + ahead[sum - price[i]];
            curr[sum] = max(take, notTake);
        }
        ahead = curr;
    }
    
    cout << curr[x] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}