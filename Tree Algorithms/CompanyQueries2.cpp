#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int LOG = 20;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n + 1);
    
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i + 1);
    }

    vector<vector<int>> up(n + 1, vector<int>(LOG, -1));
    vector<int> depth(n + 1, 0);

    function<void(int, int)> dfs = [&](int node, int parent) {
        up[node][0] = parent;

        for (int i = 1; i < LOG; i++) {
            if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            }
        }

        for (int child : adj[node]) {
            if (child != parent) {
                depth[child] = depth[node] + 1;
                dfs(child, node);
            }
        }
    };

    dfs(1, -1);

    while (q--) {
        int u, v;
        cin >> u >> v;

        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; i++) {
            if (diff & (1 << i)) {
                if (u == -1) break;
                u = up[u][i];
            }
        }

        if (u == v) {
            cout << u << '\n';
            continue;
        }

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        cout << up[u][0] << '\n';
    }

    return 0;
}
