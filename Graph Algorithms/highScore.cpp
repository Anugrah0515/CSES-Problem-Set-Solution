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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    vector<vector<pair<int, int>>> adj(n + 1);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[b].pb({a, c});
        edges.pb({a, b, -c});
    }

    vector<ll> dist(n + 1, 1e18);
    vector<bool> loop(n + 1, 0), vis(n + 1);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if (dist[u] == 1e18)
                continue;

            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;

                if (i == n - 1)
                    loop[v] = true;
            }
        }
    }
    function<void(int)> dfs = [&](int node) {
        vis[node] = 1;
        for(auto [adjNode, wt]: adj[node]) {
            if (!vis[adjNode]) {
                dfs(adjNode);
            }
        }
    };
    dfs(n);

    for (int i = 1; i <= n; i++) {
        if (loop[i] && vis[i]) {
            cout << -1;
            return;
        }
    }

    cout << -dist[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}