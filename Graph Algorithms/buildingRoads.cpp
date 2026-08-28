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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int roads = -1;
    vector<int> vis(n + 1), cities;
    function<void(int)> dfs = [&](int node) {
        vis[node] = 1;
        for(auto adjNode: adj[node]) {
            if (!vis[adjNode])
                dfs(adjNode);
        }
    };

    for(int i=1;i<=n;i++) {
        if (!vis[i]) {
            roads++;
            cities.pb(i);
            dfs(i);
        }
    }
    cout << roads << endl;
    for(int i=1;i<cities.size();i++) 
        cout << cities[i - 1] << " " << cities[i] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}