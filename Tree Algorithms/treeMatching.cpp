#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define input(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define output(a) for (auto it : a) cout << it << " ";
#define sortFcn(a) sort(a.begin(), a.end());
#define revPrint(a, n) for(int i=n-1;i>=0;i--) cout << a[i] << " ";
#define rev(a) reverse(a.begin(), a.end());
#define lowerBound(a, x) lower_bound(a.begin(), a.end(), x)
#define upperBound(a, x) upper_bound(a.begin(), a.end(), x)
#define impossible cout << "IMPOSSIBLE" << endl;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define newline cout << endl;

int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1), dp(n + 1, vector<int>(2, -1));
    for(int i=0;i<n-1;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    function<int(int, int, int)> f = [&](int node, int flag, int parent) {
        if (dp[node][flag] != -1) return dp[node][flag];
        int ans = 0;
        for(auto it: adj[node])
            if(it != parent)
                ans += f(it, 0, node);
        if(!flag) {
            int others = ans;
            for(auto it: adj[node])
                if (it != parent)
                    ans = max(ans, 1 + f(it, 1, node) + (others - f(it, 0, node)));
        }
        return dp[node][flag] = ans;
    };

    cout << f(1, 0, -1) << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}