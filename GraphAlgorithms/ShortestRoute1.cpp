#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    while(m--) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (d > dist[node]) continue;
        for(auto [adjNode, wt]: adj[node]) {
            if (dist[adjNode] > dist[node] + wt) {
                dist[adjNode] = dist[node] + wt;
                pq.push({dist[node] + wt, adjNode});
            }
        }
    }
    for(int i=0;i<n;i++)
        cout << dist[i + 1] << " ";
    cout << endl;
    return 0;
}