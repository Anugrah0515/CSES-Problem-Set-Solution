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
    int n;
    cin >> n;
    vector<int> a(n);
    input(a, n);

    int maxSum = accumulate(a.begin(), a.end(), 0);
    vector<int> dp(maxSum + 1);
    dp[0] = 1;
    for (int coin : a) {
        for (int sum = maxSum; sum >= coin; sum--) {
            if (dp[sum - coin])
                dp[sum] = true;
        }
    }
    int cnt = -1;
    for(auto it: dp)
        cnt += it;
    cout << cnt << endl;
    for(int i=1;i<dp.size();i++)
        if (dp[i])
            cout << i << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}