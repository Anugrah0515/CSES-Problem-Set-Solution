#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e18
 
ll dijkstraWithCoupon(vector<vector<pair<int, ll>>>& adj, int n) {
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
    pq.push({0, {1, 0}});
    vector<vector<ll>> dist(2, vector<ll>(n+1, INF));
    dist[0][1] = dist[1][1] = 0;
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        ll d = it.first;
        int node = it.second.first;
        int couponUsed = it.second.second;
        if (dist[couponUsed][node] < d) continue;
        if (node == n) break;
        for(auto it: adj[node]) {
            int adjNode = it.first;
            ll wt = it.second;
            if (!couponUsed) {
                if (d + wt < dist[0][adjNode]) {
                    pq.push({d + wt, {adjNode, 0}});
                    dist[0][adjNode] = d + wt;
                }
                if (d + wt / 2 < dist[1][adjNode]) {
                    pq.push({d + wt / 2, {adjNode, 1}});
                    dist[1][adjNode] = d + wt / 2;
                }
            } else {
                if (d + wt < dist[1][adjNode]) {
                    pq.push({d + wt, {adjNode, 1}});
                    dist[1][adjNode] = d + wt;
                }
            }
        }
    }
    return min(dist[0][n], dist[1][n]);
}
 
int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, ll>>> adj(n+1);
    for(int i=0;i<m;i++) {
        int a, b, wt;
        cin>>a>>b>>wt;
        adj[a].push_back({b, wt});
    }
    cout<<dijkstraWithCoupon(adj, n)<<endl;
    return 0;
}