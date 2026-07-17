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
    int a, b;
    cin >> a >> b;

    // memoization
    vector<vector<int>> dp(a + 1, vector<int>(b + 1));    
    function<int(int, int)> f = [&](int length, int width) {
        // if (length < width)
        //     swap(length, width);
        if (length == width) return 1;
        if (width == 1) return length;
        if (length == 1) return width;
        if (dp[length][width] != -1) return dp[length][width];
        int ans = 1e9;
        for(int i=1;i<width;i++) {
            ans = min(ans, f(length, i) + f(length, width - i));
        }
        for(int i=1;i<length;i++) {
            ans = min(ans, f(length - i, width) + f(i, width));
        }
        return dp[length][width] = ans;
    };

    // tabulation
    for(int i=1;i<=min(a, b);i++)
        dp[i][i] = 1;
    for(int i=1;i<=b;i++) 
        dp[1][i] = i;
    for(int i=1;i<=a;i++)
        dp[i][1] = i;
    for(int length = 2;length<=a;length++) {
        for(int width = 2;width<=b;width++) {
            if (length == width) {
                dp[length][width] = 1;
                continue;
            }
            int ans = 1e9;
            for(int i=1;i<width;i++) {
                ans = min(ans, dp[length][i] + dp[length][width - i]);
            }
            for(int i=1;i<length;i++) {
                ans = min(ans, dp[length - i][width] + dp[i][width]);
            }
            dp[length][width] = ans;
        }
    } 

    cout << dp[a][b] - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}