#include <bits/stdc++.h>
using namespace std;
#define ll long long
# define INF 1e18
 
void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
    vis[node] = 1;
    for(auto it: adj[node]) {
        if (!vis[it])
            dfs(it, vis, adj);
    }
}
 
int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adjSource(n+1), adjDest(n+1);
    vector<tuple<int, int, int>> edges(m);
    for(int i=0;i<m;i++) {
        int a, b;
        ll x;
        cin>>a>>b>>x;
        adjSource[a].push_back(b);
        adjDest[b].push_back(a);
        edges[i] = {a, b, -x};
    }
    vector<int> visSource(n+1), visDest(n+1);
    vector<ll> d(n+1, INF);
    d[1] = 0;
    dfs(1, visSource, adjSource);
    dfs(n, visDest, adjDest);
    bool flag = 0;
    for(int i=1;i<=n;i++) {
        flag = 0;
        for(auto it: edges) {
            int u, v, x;
            tie(u, v, x) = it;
            if (visSource[u] && visDest[v] && d[u] + x < d[v]) {
                flag = 1;
                d[v] = d[u] + x;
            }
        }
    }
    if (flag) cout << -1 << endl;
    else cout << -d[n] << endl;
    return 0;
}
