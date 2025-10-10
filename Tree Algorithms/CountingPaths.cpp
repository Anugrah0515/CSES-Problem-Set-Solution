#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n + 1);
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int LOG = 20;
    vector<vector<int>> up(n + 1, vector<int>(LOG, -1));
    vector<int> depth(n + 1, 0), ans(n + 1, 0);
    function<void(int, int)> dfs = [&](int node, int p) {
        up[node][0] = p;
        for(int i=1;i<LOG;i++) {
            if (up[node][i - 1] != -1) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            } else up[node][i] = -1;
        }
        for(auto it: adj[node]) {
            if (it != p) {
                depth[it] = depth[node] + 1;
                dfs(it, node);
            }
        }
    };

    function<int(int, int)> lca = [&](int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for(int i=0;i<LOG;i++) {
            if (diff & (1 << i)) {
                if (u == -1) break;
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for(int i=LOG - 1;i>=0;i--) {
            if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    };

    function<void(int, int)> dfs_count = [&](int node, int p) {
        for(auto it: adj[node]) {
            if (it != p) {
                dfs_count(it, node);
                ans[node] += ans[it];
            }
        }
    };
    dfs(1, -1);
    
    while(m--) {
        int u, v;
        cin >> u >> v;
        int l = lca(u, v);
        ans[u]++;
        ans[v]++;
        ans[l]--;
        if (up[l][0] != -1) ans[up[l][0]]--;
    }
    dfs_count(1, -1);
    for(int i=1;i<=n;i++) 
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}