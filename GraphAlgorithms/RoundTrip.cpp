#include <bits/stdc++.h>
using namespace std;
 
bool found = false;
 
void printPath(int node, vector<int>& path) {
    found = true;
    int count = 1;
    string res = to_string(node) + " ";
    for(int i = path.size() - 1; i >= 0; i--) {
        res += to_string(path[i]);
        count++;
        if (path[i] == node) break;
        else res += " ";
    }
    cout << count << endl << res << endl;
}
 
void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj, vector<int>& path) {
    if(found) return;
    else if (vis[node]) {
        if (path.size() > 2) {
            printPath(node, path);
        }
        return;
    }
    vis[node] = 1;
    path.push_back(node);
    for(auto it: adj[node]) {
        if (it == parent) continue;
        dfs(it, node, vis, adj, path);
    }
    path.pop_back();
}
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n+1);
    for(int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> path;
            dfs(i, -1, vis, adj, path);
        }
    }
    if(!found) cout << "IMPOSSIBLE" << endl;
    return 0;
}