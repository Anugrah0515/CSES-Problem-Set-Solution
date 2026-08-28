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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, ll>>> adj(n + 1);
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    vector<vector<ll>> minDist(n + 1, vector<ll>(n + 1, 1e18));
    for(int i=1;i<=n;i++) {
        for(auto [j, wt]: adj[i]) {
            minDist[i][j] = minDist[j][i] = min({minDist[i][j], minDist[j][i], wt});
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            for(int k=1;k<=n;k++) {
                if (j == k) {
                    minDist[j][k] = 0;
                    continue;
                }
                minDist[j][k] = min(minDist[j][k], minDist[j][i] + minDist[i][k]);
            }
        }
    }
    for(auto &it: minDist)
        for(auto &i: it) 
            i = (i == 1e18 ? -1 : i);
    while(q--) {
        int start, end;
        cin >> start >> end;
        cout << minDist[start][end] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}