#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, LLONG_MAX));

    for (int i = 1; i <= n; i++) {
        adj[i][i] = 0;
    }

    while (m--) {
        int u, v;
        ll wt;
        cin >> u >> v >> wt;
        adj[u][v] = min(adj[u][v], wt);
        adj[v][u] = min(adj[v][u], wt);
    }

    vector<vector<ll>> dist = adj;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (dist[i][k] == LLONG_MAX) continue;
            for (int j = 1; j <= n; j++) {
                if (dist[k][j] == LLONG_MAX) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] == LLONG_MAX) cout << -1 << "\n";
        else cout << dist[u][v] << "\n";
    }

    return 0;
}
