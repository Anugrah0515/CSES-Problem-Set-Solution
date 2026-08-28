#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define input(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define output(a) for (auto it : a) cout << it << " ";
#define sortFcn(a) sort(a.begin(), a.end());
#define rev(a) reverse(a.begin(), a.end());
#define revPrint(a, n) for(int i=n-1;i>=0;i--) cout << a[i] << " ";
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

    vector<int> vis(n + 1), parent(n + 1);
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node == n) {
            vector<int> path;
            while(node != 1) {
                path.pb(node);
                node = parent[node];
            }
            path.pb(1);
            cout << path.size() << endl;
            revPrint(path, path.size());
            cout << endl;
            return;
        }
        for(auto adjNode: adj[node]) {
            if (!vis[adjNode]) {
                vis[adjNode] = 1;
                parent[adjNode] = node;
                q.push(adjNode);
            }
        }
    }
    impossible
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}