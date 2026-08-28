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
#define newline cout << endl;

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
    bool flag = false;
    vector<int> path;
    function<void(int)> dfs = [&](int node) {
        if (flag) return;
        vis[node] = 1;
        for(auto adjNode: adj[node]) {
            if (!vis[adjNode]) {
                parent[adjNode] = node;
                dfs(adjNode);
                if (flag) return;
            } else if (adjNode != parent[node]) {
                flag = true;
                path.pb(adjNode);
                int curr = node;
                while(curr != adjNode) {
                    path.pb(curr);
                    curr = parent[curr];
                }
                path.pb(curr);
                return;
            }
        }
    };
    for(int i=1;i<=n;i++) {
        if (!vis[i]) {
            dfs(i);
            if (flag) break;
        }
    }
    if (flag) {
        cout << path.size() << endl;
        output(path);
    } else 
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