#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> minDist(vector<vector<int>>& adj, int n) {
    vector<int> vis(n+1), parent(n+1);
    vis[1] = 1;
    queue<pair<int, int>>q;
    q.push({0, 1});
    while(!q.empty()) {
        int node = q.front().second;
        int dist = q.front().first;
        q.pop();
        if (node == n) {
            vector<int> path;
            while (node != 1) {
                int d = parent[node];
                path.push_back(node);
                node = d;
            }
            path.push_back(node);
            reverse(path.begin(), path.end());
            return path;
        }
        for(auto it: adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                parent[it] = node;
                q.push({dist + 1, it});
            }
        }
    }
    return {};
}
 
int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> path = minDist(adj, n);
    if (path.size() == 0) cout<<"IMPOSSIBLE"<<endl;
    else {
        cout<<path.size()<<endl;
        for(auto it: path) cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}