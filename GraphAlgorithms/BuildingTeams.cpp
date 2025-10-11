#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isBipartite = true;
    vector<int> vis(n + 1), teamAssigned(n + 1);
    function<void(int, int, int)> dfs = [&](int node, int p, int team) {
        vis[node] = 1;
        teamAssigned[node] = team;
        for(auto it: adj[node]) {
            if (!vis[it]) {
                dfs(it, node, team == 1 ? 2 : 1);
            } else if (it != p && teamAssigned[it] == team) {
                isBipartite = false;
            }
        }
    };
    for(int i=1;i<=n;i++) {
        if (!vis[i])
            dfs(i, -1, 1);
    }
    if (isBipartite) {
        for(int i=0;i<n;i++) 
            cout << teamAssigned[i + 1] << " ";
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}